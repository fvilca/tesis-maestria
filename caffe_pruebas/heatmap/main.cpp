#include <opencv2/opencv.hpp>
#include <iostream>

#include <caffe/caffe.hpp>
#include <caffe/net.hpp>
#include <caffe/blob.hpp>

#include <vector>
#include <algorithm>


using namespace caffe;
using namespace std;
using namespace cv;


int bias  = 0;
int bytes = 0;
//typename boost::shared_ptr<Net<float> > Net;
int check_image_empty(Mat &image){
    if (image.empty())  //Check for failure
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for key press
        return -1;
    }
}
/////////////////////////////////////////////////////////////////
int main(int argc, char ** argv){
	
	std::cout<<"init"<<endl;
	
    string model_file = argv[1];	// Input argument with model prototxt file
    string weights_file = argv[2];	// Input argument with caffemodel weights
    string image_file   = argv[3];	// Input argument with image file name

    //Use GPU 0
    Caffe::set_mode(Caffe::GPU);
    int device_id = 0;
    Caffe::SetDevice(device_id);

    // Set up a shared pointer for the network
    boost::shared_ptr<Net<float> > net;
    	net.reset(new Net<float>(model_file, TEST)); 	// Load the model
    	net->CopyTrainedLayersFrom(weights_file);		// Copy the pretrained weights
		std::cout << "LOADED CAFFE MODEL\n";			// Tell us if the model loads properly


	//Extract layer information
	  cout << "Num layers:" << "'" << net->layer_names().size() << "'"<< endl;
	  for (int layer_index = 0; layer_index < net->layer_names().size(); ++layer_index) 
	  {
	        // get that layer blob and its dimension
	        const boost::shared_ptr<Blob<float> > blob = net->blob_by_name(net->blob_names()[layer_index]);
	        int batch_size = blob->num();                
	        int dim_features = blob->count() / batch_size;
	        std::cout << "Layer name:" << "'" << net->layer_names()[layer_index] << "'" << " Blob name:" << "'" <<net->blob_names()[layer_index] << "'" << " batch size " << "'" << batch_size << "'" << " dim_features:" << "'" << dim_features << "'" <<  std::endl;
	  }


    Mat image = imread(image_file);		// Read in the image file
    	check_image_empty(image);
	    int imgH = image.rows;
	    int imgW = image.cols;
	    cout<<"Image size is "<<imgW<<"x"<<imgH<<" with "<<image.channels()<< " channels"<<endl;
	
    String windowName = "Image Display";
    namedWindow(windowName); //create window

    imshow(windowName,image); //show the image

    waitKey(0); //Wait for any keystroke in the window
    destroyWindow(windowName); // remove the window

    //Create vector for the image
    vector<cv::Mat> imageVector;
    imageVector.push_back(image); // image is a cv::Mat, push_back pushes the image into the vector

    //Create vector for the network output, it might be a Mat?
    vector<cv::Mat> outputVector;

    // Get the first layer in the network
    boost::shared_ptr<Blob<float> > input;
    input = net->blob_by_name("img");
	
	
    // Check if to see if it's empty.  If not, reshape it to [batch,channels,height,width]
    if(input != nullptr){
        input->Reshape(1,3,imgH,imgW);
        bias = input->offset(0, 1, 0, 0);  // Not sure what these lines do, I found it in a code snippet
        bytes = bias*sizeof(float);        // and bytes gets called during the memcpy
    }
    
    // Reshape the net to reflect the changes
    net->Reshape();

    // Copy the image data to the input layer
    memcpy(input->mutable_cpu_data(), image.data, bytes);
    
    // Forward pass of the net
    net->Forward();

    // Get the output
    boost::shared_ptr<Blob<float>> output;
    output = net->blob_by_name("prob_image");
    
     // Turn the output into a "human readable" 1D valarray
    // heatmap1D is now [(imgH x imgW x numClasses) x 1]
    const float* tmp = output->cpu_data();
    
    vector<float> heatmap1D;

    for(int i=0;i<(imgW*imgH*4);i++){
        heatmap1D.push_back(tmp[i]);
    }
    /*
    // Get the min and max for scaling back to [0,255]
    auto minmax = minmax_element(begin(heatmap1D), end(heatmap1D));

    // Values used for normalization
    float max = *minmax.second;
    float min = *minmax.first;
    float range = max-min;
    float tval=0;
    
    // Normalize the array
    for(int i=0;i<(imgW*imgH*4);i++){
        tval = (heatmap1D[i]-min)/range;
        heatmap1D[i]=tval*255;
    }

    // Initialize a 2D array
    float heatmap2D[imgH][imgW];
    // Fill it with the values from the 1D array
    for(int i=0;i<imgH;i++){
        for(int j=0;j<imgW;j++){
            heatmap2D[i][j]=heatmap1D[i*j];
        }
    }

    // Put the 2D array into an OpenCV Mat 
    cv::Mat m = cv::Mat(imgH,imgW,CV_8UC1,&heatmap2D);

    namedWindow(windowName); //create window

    imshow(windowName,m); //show the image

    waitKey(0); //Wait for any keystroke in the window
    destroyWindow(windowName); // remove the window
    */



	std::cout<<"fin"<<endl;	
	return 0;
}
