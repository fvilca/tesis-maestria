// Copyright 2014-2015 Isis Innovation Limited and the authors of gSLICr

#include <time.h>
#include <stdio.h>

#include "gSLICr_Lib/gSLICr.h"
#include "NVTimer.h"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"



using namespace std;
using namespace cv;

void load_image(const Mat& inimg, gSLICr::UChar4Image* outimg)
{
	gSLICr::Vector4u* outimg_ptr = outimg->GetData(MEMORYDEVICE_CPU);

	for (int y = 0; y < outimg->noDims.y;y++)
		for (int x = 0; x < outimg->noDims.x; x++)
		{
			int idx = x + y * outimg->noDims.x;
			outimg_ptr[idx].b = inimg.at<Vec3b>(y, x)[0];
			outimg_ptr[idx].g = inimg.at<Vec3b>(y, x)[1];
			outimg_ptr[idx].r = inimg.at<Vec3b>(y, x)[2];
		}
}

void load_image(const gSLICr::UChar4Image* inimg, Mat& outimg)
{
	const gSLICr::Vector4u* inimg_ptr = inimg->GetData(MEMORYDEVICE_CPU);

	for (int y = 0; y < inimg->noDims.y; y++)
		for (int x = 0; x < inimg->noDims.x; x++)
		{
			int idx = x + y * inimg->noDims.x;
			outimg.at<Vec3b>(y, x)[0] = inimg_ptr[idx].b;
			outimg.at<Vec3b>(y, x)[1] = inimg_ptr[idx].g;
			outimg.at<Vec3b>(y, x)[2] = inimg_ptr[idx].r;
		}
}



int main()
{
	
	// gSLICr settings
	gSLICr::objects::settings my_settings;
	my_settings.img_size.x = 183;//400
	my_settings.img_size.y = 180;//253
	my_settings.no_segs = 20;//1000
	my_settings.spixel_size = 20;//20
	my_settings.coh_weight = 1.5f; //0.6f;
	my_settings.no_iters = 5;
	my_settings.color_space =gSLICr::RGB; //gSLICr::CIELAB;
	//my_settings.seg_method = gSLICr::GIVEN_NUM;
	my_settings.seg_method = gSLICr::GIVEN_SIZE;
	my_settings.do_enforce_connectivity = true;

	// instantiate a core_engine
	gSLICr::engines::core_engine* gSLICr_engine = new gSLICr::engines::core_engine(my_settings);

	// gSLICr takes gSLICr::UChar4Image as input and out put
	gSLICr::UChar4Image* in_img = new gSLICr::UChar4Image(my_settings.img_size, true, true);
	gSLICr::UChar4Image* out_img = new gSLICr::UChar4Image(my_settings.img_size, true, true);

	Size s(my_settings.img_size.x, my_settings.img_size.y);
	Mat oldFrame, frame;
	Mat boundry_draw_frame; boundry_draw_frame.create(s, CV_8UC3);

	oldFrame = imread("digit/2.PNG");
	resize(oldFrame, frame, s);
	load_image(frame, in_img);


	cout<<"listo"<<endl;
	//TODO
	
    
	//gSLICr_engine->Process_Frame2(in_img);
	gSLICr_engine->Process_Frame(in_img);
	

	//*****************
	gSLICr_engine->merge();

    gSLICr_engine->Draw_Segmentation_Result(out_img);
	load_image(out_img, boundry_draw_frame);
	imshow("segmentation", boundry_draw_frame);

	//imshow("input",oldFrame);

	waitKey(0);
			
	char out_name[100];
	
	

	sprintf(out_name, "seg_%04i.pgm", 1);
	gSLICr_engine->Write_Seg_Res_To_PGM(out_name);
		
	
	sprintf(out_name, "edge_%04i.png", 1);
	imwrite(out_name, boundry_draw_frame);

	//sprintf(out_name, "img_%04i.png", 1);
	//imwrite(out_name, frame);

	printf("\nsaved segmentation %04i\n", 1);
	
		
    return 0;
}
