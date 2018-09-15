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

int main(int argc, char ** argv){
	
	std::cout<<"init"<<endl;
	string model_file = argv[1];		//prototxt file
	string weights_file = argv[2];		//caffe model weights
	string image_file = argv[3];		

	Caffe::set_mode(Caffe::GPU);
	int device_id = 0;
	Caffe::SetDevice(device_id);

	boost::shared_ptr<Net<float> > net;
	net.reset(new Net<float>(model_file, TEST));
	net.CopyTrainedLayersFrom(weights_file);

	Mat image = imread(image_file);
	int imgH = image.rows;
	int imgW = image.cols;

	//**********************************

	vector<cv::Mat> imageVector;
	imageVector.push_back(image); 

	vector<cv::Mat> outputVector;

	//obten la primera capa en la red
	//Blob<float> input;
	boost::shared_ptr<Blob<float> > input;
	input = net->blob_by_name("data");
	if(input != nullptr){	
		std::cout<<"vacio"<<endl;			
	}	
/*
	net->Reshape();

	memcpy(input->mutable_cpu_data(), image.data, bytes);

	net->Forward();

	Blob<float> heatmap;
	heatmap= net->blob_by_name("score");

*/
	std::cout<<"fin"<<endl;	
	return 0;
}
