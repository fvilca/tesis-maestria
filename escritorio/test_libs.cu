#include <thrust/binary_search.h>
#include <thrust/fill.h>
#include <thrust/copy.h>
#include <thrust/count.h>
#include <thrust/device_ptr.h>
#include <thrust/device_vector.h>
#include <thrust/execution_policy.h>
#include <thrust/extrema.h>
#include <thrust/functional.h>
#include <thrust/host_vector.h>

#include <thrust/memory.h>
//#include <thrust/pair.h>
//#include <thrust/random.h>
//#include <thrust/reduce.h>
#include <thrust/sequence.h>
//#include <thrust/sort.h>
#include <thrust/scan.h>
#include <thrust/unique.h>
//#include <thrust/tuple.h>
//#include <thrust/iterator/zip_iterator.h>
//#include <thrust/iterator/constant_iterator.h>
//#include <thrust/iterator/counting_iterator.h>
#include <thrust/system/cuda/execution_policy.h>

#include "vector_types.h"
#include <cstdio>

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include "CImg.h"
using namespace cimg_library;

#include <iostream>
#include <fstream>
#include <string>

#include <stdio.h>
#include <curand_kernel.h>
#include <helper_math.h>


const int N = 16; 
const int blocksize = 16; 


__global__ 
void hello(char *a, int *b) {

	a[threadIdx.x] += b[threadIdx.x];
}

using namespace std;

int main(){

	string str = " ... ";
	int num = 5;
	str += to_string(num);
	cout<<"str: "<<str<<endl;

	volatile float4 f4;
	volatile int2 i2;
	
	char a[N] = "siii \0\0\0\0\0\0";
	int b[N] = {15, 10, 6, 0, -11, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 
	char *ad;
	int *bd;
	const int csize = N*sizeof(char);
	const int isize = N*sizeof(int);
 
	printf("%s", a);
 
	cudaMalloc( (void**)&ad, csize ); 
	cudaMalloc( (void**)&bd, isize ); 
	cudaMemcpy( ad, a, csize, cudaMemcpyHostToDevice ); 
	cudaMemcpy( bd, b, isize, cudaMemcpyHostToDevice ); 
	
	dim3 dimBlock( blocksize, 1 );
	dim3 dimGrid( 1, 1 );
	hello<<<dimGrid, dimBlock>>>(ad, bd);
	cudaMemcpy( a, ad, csize, cudaMemcpyDeviceToHost ); 
	cudaFree( ad );
	cudaFree( bd );
	
	printf("%s\n", a);
	return EXIT_SUCCESS;
}

