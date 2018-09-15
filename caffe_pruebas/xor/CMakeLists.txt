cmake_minimum_required(VERSION 2.8)
PROJECT(caffe_pruebas)

find_package(OpenCV REQUIRED)
find_package(Caffe REQUIRED)

#include_directories( "${PROJECT_SOURCE_DIR}/include" )
#add_subdirectory( src )
add_definitions(-std=c++0x)
include_directories(${Caffe_INCLUDE_DIRS})
add_executable(testnet test.cpp)
#target_link_libraries( caffe_pruebas ${OpenCV_LIBS} c2 ${Caffe_LIBRARIES} )
target_link_libraries( testnet ${Caffe_LIBRARIES} )    #agrrega al executable las libs    


#Now, the following commands from inside the project directory will create the executable MyProject inside the build folder.
#mkdir build
#cd build
#cmake ..
#make

#You can then run your program with ./MyProject (arguments)
