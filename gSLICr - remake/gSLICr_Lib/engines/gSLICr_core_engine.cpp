// Copyright 2014-2015 Isis Innovation Limited and the authors of gSLICr

#pragma once
#include "gSLICr_core_engine.h"

#include <fstream>
#include <iostream>

using namespace gSLICr;
using namespace std;

gSLICr::engines::core_engine::core_engine(const objects::settings& in_settings)
{
	slic_seg_engine = new seg_engine_GPU(in_settings);
}

gSLICr::engines::core_engine::~core_engine()
{
		delete slic_seg_engine;
}

void gSLICr::engines::core_engine::Process_Frame(UChar4Image* in_img)
{
	slic_seg_engine->Perform_Segmentation(in_img);
}

void gSLICr::engines::core_engine::Process_Frame2(UChar4Image* in_img)
{
	slic_seg_engine->Perform_Segmentation2(in_img);
}

const IntImage * gSLICr::engines::core_engine::Get_Seg_Res()
{
	return slic_seg_engine->Get_Seg_Mask();
}

void gSLICr::engines::core_engine::Draw_Segmentation_Result(UChar4Image* out_img)
{
	slic_seg_engine->Draw_Segmentation_Result(out_img);
}
///////////////////////////////////////////////////////////////////
void gSLICr::engines::core_engine::merge(){

	slic_seg_engine->merge();

}

void gSLICr::engines::core_engine::Write_Seg_Res_To_PGM(const char* fileName)
{
	const IntImage* idx_img = slic_seg_engine->Get_Seg_Mask();
	int width = idx_img->noDims.x;
	int height = idx_img->noDims.y;
	const int* data_ptr = idx_img->GetData(MEMORYDEVICE_CPU);

	//ofstream f(fileName, std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);
	ofstream f(fileName, std::ios_base::out |  std::ios_base::trunc);
	f << "P5\n" << width << " " << height << "\n65535\n";
	for (int i = 0; i < height * width; ++i)
	{
		ushort lable = (ushort)data_ptr[i];
		ushort lable_buffer = (lable << 8 | lable >> 8);
		f.write((const char*)&lable_buffer, sizeof(ushort));
	}
	f.close();

	int x,y;
	ofstream fout("final.txt");
	for(x = 0;x < width;x++)
	{
	 	for(y = 0;y < height;y++)
	 	{
	 		int idx_img = y * width + x;
	 		fout<<data_ptr[idx_img]<<",";
	 	}
	 	fout<<endl;
	 }
	 f.close();
}



