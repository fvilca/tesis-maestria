#include <vtkSmartPointer.h>

#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkIdList.h>
#include <vtkCell.h>
#include <vtkTriangleFilter.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkIdTypeArray.h>
#include <vtkSelectionNode.h>
#include <vtkSelection.h>
#include <vtkExtractSelection.h>
#include <vtkProperty.h>

#include <vtkNamedColors.h>

#include <list>


#include <vtkVersion.h>
#include <vtkPoints.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkCellData.h>
#include <vtkCellArray.h>
#include <vtkTriangle.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPolyDataMapper.h>
// For compatibility with new VTK generic data arrays
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif



//a color for each cell
void setColors(vtkSmartPointer<vtkUnsignedCharArray>&cellData, int numofCells){
	// Create cell data
  vtkMath::RandomSeed(8775070); // for reproducibility
   
  cellData->SetNumberOfComponents(3);
  cellData->SetNumberOfTuples(numofCells);

  	for (int i = 0; i < numofCells; i++) {
	    float rgb[3];
	    rgb[0] = vtkMath::Random(64, 255);
	    rgb[1] = vtkMath::Random(64, 255);
	    rgb[2] = vtkMath::Random(64, 255);
	    cellData->InsertTuple(i, rgb);
    }
}

int main(int, char *[])
{
 //Create a sphere
  vtkSmartPointer<vtkSphereSource> sphereSource =
      vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();
 
  vtkSmartPointer<vtkTriangleFilter> triangleFilter =
    vtkSmartPointer<vtkTriangleFilter>::New();
  triangleFilter->SetInputConnection(sphereSource->GetOutputPort());
  triangleFilter->Update();

  vtkSmartPointer<vtkPolyData> originalMesh;
  originalMesh = triangleFilter->GetOutput();
  
  std::cout << "    There are " << originalMesh->GetNumberOfPolys()
            << " triangles." << std::endl;

  std::cout << "    There are " << originalMesh->GetNumberOfPoints()
            << " points." << std::endl;

  std::cout << "    There are " << triangleFilter->GetOutput()->GetNumberOfCells()
            << " cells." << std::endl;

  	vtkSmartPointer<vtkUnsignedCharArray> cellData =    vtkSmartPointer<vtkUnsignedCharArray>::New();
 	setColors(cellData, triangleFilter->GetOutput()->GetNumberOfCells() );
	 

 	originalMesh->GetCellData()->SetScalars(cellData);

  cout<<"::"<<originalMesh->GetNumberOfPoints()<<endl;

 	// Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
#if VTK_MAJOR_VERSION <= 5
  mapper->SetInputConnection(originalMesh->GetProducerPort());
#else
  mapper->SetInputData(originalMesh);
#endif
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);
 
  renderer->AddActor(actor);
  renderer->ResetCamera();
 
  renderWindow->Render();
  renderWindowInteractor->Start();


/*
  // Find all cells connected to point 0
  vtkIdType cellId = 0;

  vtkSmartPointer<vtkIdList> cellPointIds = vtkSmartPointer<vtkIdList>::New();

  triangleFilter->GetOutput()->GetCellPoints(cellId,cellPointIds);

  std::list<vtkIdType> neighbors;
  
  cout<< "vertices de la celda 0:  " 
  	  <<  cellPointIds->GetNumberOfIds()
  	  << endl;

  
  for(vtkIdType i = 0; i < cellPointIds->GetNumberOfIds(); i++)
  {
    vtkSmartPointer<vtkIdList> idList =
      vtkSmartPointer<vtkIdList>::New();
    idList->InsertNextId(cellPointIds->GetId(i));

    //get the neighbors of the cell
    vtkSmartPointer<vtkIdList> neighborCellIds =
      vtkSmartPointer<vtkIdList>::New();

    triangleFilter->GetOutput()->GetCellNeighbors(cellId, idList, neighborCellIds);

    for(vtkIdType j = 0; j < neighborCellIds->GetNumberOfIds(); j++)
    {
      neighbors.push_back(neighborCellIds->GetId(j));
    }

  }

  std::cout << "Point neighbor ids are: " << std::endl;

  for(std::list<vtkIdType>::iterator it1 = neighbors.begin(); it1 != neighbors.end(); it1++)
  {
    std::cout << " " << *it1;
  }
  std::cout << std::endl;

////////
  vtkSmartPointer<vtkNamedColors> colors =
    vtkSmartPointer<vtkNamedColors>::New();

  vtkSmartPointer<vtkDataSetMapper> sphereMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  sphereMapper->SetResolveCoincidentTopologyToPolygonOffset();

  vtkSmartPointer<vtkActor> sphereActor =
    vtkSmartPointer<vtkActor>::New();
  sphereActor->SetMapper(sphereMapper);
  sphereActor->GetProperty()->SetEdgeColor(colors->GetColor3d("Lamp_Black").GetData());
  sphereActor->GetProperty()->EdgeVisibilityOn();
  sphereActor->GetProperty()->SetLineWidth(3);

  vtkSmartPointer<vtkDataSetMapper> mainCellMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();

  vtkSmartPointer<vtkDataSetMapper> neighborCellsMapper =
    vtkSmartPointer<vtkDataSetMapper>::New();

  // Create a dataset with the cell of interest
  {
    vtkSmartPointer<vtkIdTypeArray> ids =
        vtkSmartPointer<vtkIdTypeArray>::New();
    ids->SetNumberOfComponents(1);
    ids->InsertNextValue(cellId);

    vtkSmartPointer<vtkSelectionNode> selectionNode =
      vtkSmartPointer<vtkSelectionNode>::New();
    selectionNode->SetFieldType(vtkSelectionNode::CELL);
    selectionNode->SetContentType(vtkSelectionNode::INDICES);
    selectionNode->SetSelectionList(ids);

    vtkSmartPointer<vtkSelection> selection =
        vtkSmartPointer<vtkSelection>::New();
    selection->AddNode(selectionNode);

    vtkSmartPointer<vtkExtractSelection> extractSelection =
        vtkSmartPointer<vtkExtractSelection>::New();
    extractSelection->SetInputConnection(0, sphereSource->GetOutputPort());
    extractSelection->SetInputData(1, selection);
    extractSelection->Update();

    mainCellMapper->SetInputConnection(extractSelection->GetOutputPort());

  }

  vtkSmartPointer<vtkActor> mainCellActor =
    vtkSmartPointer<vtkActor>::New();
  mainCellActor->SetMapper(mainCellMapper);
  mainCellActor->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());

  // Create a dataset with the neighbor cells
  {
    vtkSmartPointer<vtkIdTypeArray> ids =
        vtkSmartPointer<vtkIdTypeArray>::New();
    ids->SetNumberOfComponents(1);
    for(std::list<vtkIdType>::iterator it1 = neighbors.begin(); it1 != neighbors.end(); it1++)
    {
      ids->InsertNextValue(*it1);
    }

    vtkSmartPointer<vtkSelectionNode> selectionNode =
      vtkSmartPointer<vtkSelectionNode>::New();
    selectionNode->SetFieldType(vtkSelectionNode::CELL);
    selectionNode->SetContentType(vtkSelectionNode::INDICES);
    selectionNode->SetSelectionList(ids);

    vtkSmartPointer<vtkSelection> selection =
        vtkSmartPointer<vtkSelection>::New();
    selection->AddNode(selectionNode);

    vtkSmartPointer<vtkExtractSelection> extractSelection =
        vtkSmartPointer<vtkExtractSelection>::New();
    extractSelection->SetInputConnection(0, sphereSource->GetOutputPort());
    extractSelection->SetInputData(1, selection);
    extractSelection->Update();

    neighborCellsMapper->SetInputConnection(extractSelection->GetOutputPort());

  }

  vtkSmartPointer<vtkActor> neighborCellsActor =
    vtkSmartPointer<vtkActor>::New();
  neighborCellsActor->SetMapper(neighborCellsMapper);
  neighborCellsActor->GetProperty()->SetColor(colors->GetColor3d("Mint").GetData());

  //Create a renderer, render window, and interactor
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderWindow);

  //Add the actors to the scene
  renderer->AddActor(sphereActor);
  renderer->AddActor(mainCellActor);
  renderer->AddActor(neighborCellsActor);
  renderer->SetBackground(colors->GetColor3d("Slate_grey").GetData());

  //Render and interact
  renderWindow->SetSize(640, 480);
  renderWindow->Render();
  renderWindowInteractor->Start();*/

  return EXIT_SUCCESS;
}
