#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0;
    stringstream ss;    
    ifstream infile("2007_000323.pgm", ios::binary);

    string inputLine = "";

    getline(infile,inputLine);      // read the first line : P5
    if(inputLine.compare("P5") != 0) cerr << "Version error" << endl;
    cout << "Version : " << inputLine << endl;
    
    getline(infile,inputLine);  // read the second line : comment
    cout << "Comment : " << inputLine << endl;

    ss << infile.rdbuf();   //read the third line : width and height
    ss >> num_of_cols >> num_of_rows;
    cout << num_of_cols << " columns and " << num_of_rows << " rows" << endl;

    int max_val;  //maximum intensity value : 255
    ss >> max_val;
    cout<<max_val;
    
    unsigned int pixel;

	int **pixel_value = new int*[num_of_rows];
    for(int i = 0; i < num_of_rows; ++i) {
        pixel_value[i] = new int[num_of_cols];
    }

	int **integral = new int*[num_of_rows];
    for(int i = 0; i < num_of_rows; ++i) {
        integral[i] = new int[num_of_cols];
    }

    for (row = 0; row < num_of_rows; row++){    //record the pixel values
        for (col = 0; col < num_of_cols; col++){
             ss >> pixel;
             pixel_value[row][col]= pixel;
        }
        cout << endl;
    }
    
    
	integral[0][0]=pixel_value[0][0];    
	for(int i=1; i<num_of_cols;i++){            //compute integral image
		integral[0][i]=integral[0][i-1]+pixel_value[0][i];		
	}	
	for (int i=1;i<num_of_rows; i++){
		integral[i][0]=integral[i-1][0]+pixel_value[i][0];
	}
		for (int i = 1; i < num_of_rows; i++){  
    	for (int j = 1; j < num_of_cols; j++){
    	integral[i][j] = integral[i - 1 ][j] + integral [i][j - 1] - integral[i - 1] [j - 1] + pixel_value[i][j]; 		
		}
	}
	
    ofstream output1("pixel_value.txt");  // output the intensity values of the pgm file
    for (int k=0; k<num_of_rows; k++)
    {
        for (int r=0; r<num_of_cols; r++)
        {
            output1 << pixel_value[k][r] << " ";
        }
        output1 << ";" << endl;
    }
    
    ofstream output2("integral_value.txt");    // output the integral image
    for (int a=0; a<num_of_rows; a++)
    {
        for (int b=0; b<num_of_cols; b++)
        {
            output2 << integral[a][b] << " ";
        }
        output2 << ";" << endl;
    }

	for(int i = 0; i < num_of_rows; ++i) {
        delete [] pixel_value[i];
	}
    delete [] pixel_value;

	for(int i = 0; i < num_of_rows; ++i) {
        delete [] integral[i];
	}
    delete [] integral;

infile.close();  

return 0;
}






/*#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
using namespace std;


void func(){
    FILE *pArq;
    pArq = fopen("2007_000323.pgm", "ab");

    char line1[2], line2[100], line3[10];

    int cont = 1;
    while(1){
        if(cont ==1){ //version
            fscanf(pArq, "%s", &line1);
            if(feof(pArq)) break;

            printf("%s", line1);
        }

        if(cont ==2){ //comment
            fscanf(pArq, "%s", &line2);
            if(feof(pArq)) break;

            printf("%s", line2);
        }

        if(cont ==3){ //width, height
            fscanf(pArq, "%s", &line3);
            if(feof(pArq)) break;

            printf("%s", line3);
        }

        cont++;
    }
    fclose(pArq);

	cout<<"**** "<<endl;
}

int main() {


  int row = 0, col = 0, numrows = 0, numcols = 0;
  ifstream infile("2007_000323.pgm");
  stringstream ss;
  string inputLine = "";

  // First line : version
  getline(infile,inputLine);
  if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;
  else cout << "Version : " << inputLine << endl;

  // Second line : comment
  getline(infile,inputLine);
  cout << "Comment : " << inputLine << endl;

  // Continue with a stringstream
  ss << infile.rdbuf();
  // Third line : size
  ss >> numcols >> numrows;
  cout << numcols << " columns and " << numrows << " rows" << endl;

  int array[numrows][numcols];

  // Following lines : data
  for(row = 0; row < numrows; ++row)
    for (col = 0; col < numcols; ++col) ss >> array[row][col];

  // Now print the array to see the result
  for(row = 0; row < numrows; ++row) {
    for(col = 0; col < numcols; ++col) {
      cout << array[row][col] << " ";
    }
    cout << endl;
  }
  infile.close();
}
*/

/*
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    int row = 0, col = 0, num_of_rows = 0, num_of_cols = 0, bits;
    ifstream infile("testfile.pgm", ios::binary);
    stringstream ss;    
    string inputLine = "";

    getline(infile,inputLine);      // read the first line : P5
    if(inputLine.compare("P5") != 0) cerr << "Version error" << endl;
    cout << "Version : " << inputLine << endl;

    getline(infile,inputLine);  // read the second line : comment
    cout << "Comment : " << inputLine << endl;

    ss << infile.rdbuf();   //read the third line : width and height
    ss >> num_of_cols >> num_of_rows;
    cout << num_of_cols << " columns and " << num_of_rows << " rows" << endl;

    int max_val;  //maximum intensity value : 255
    ss >> max_val;
    cout<<max_val;

    unsigned char pixel;
    unsigned int pixel_value[num_of_rows][num_of_cols];
    unsigned int integral[num_of_rows][num_of_cols];

    for (row = 0; row < num_of_rows; row++){    //record the pixel values
        for (col = 0; col < num_of_cols; col++){
             ss >> pixel;
             pixel_value[row][col]= pixel;
        }
        cout << endl;
    }

    for(int i=0; i<num_of_cols;i++){            //compute integral image
        integral[0][i]=integral[0][i-1]+pixel_value[0][i];      
    }   
    for (int i=0;i<num_of_rows; i++){
        integral[i][0]=integral[i-1][0]+pixel_value[i][0];
    }
    for (int i = 1; i < num_of_rows; i++){  
    for (int j = 1; j < num_of_cols; j++){
        integral[i][j] = integral[i - 1 ][j] + integral [i][j - 1] - integral[i - 1] [j - 1] + pixel_value[i][j];       
        }
    }

    ofstream output1("pixel_value.txt");  // output the intensity values of the pgm file
    for (int k=0; k<num_of_rows; k++)
    {
        for (int r=0; r<num_of_cols; r++)
        {
            output1 << pixel_value[k][r] << " ";
        }
        output1 << ";" << endl;
    }

    ofstream output2("integral_value.txt");    // output the integral image
    for (int a=0; a<num_of_rows; a++)
    {
        for (int b=0; b<num_of_cols; b++)
        {
            output2 << integral[a][b] << " ";
        }
        output2 << ";" << endl;
    } 

infile.close();  
return 0;  
}

*/
