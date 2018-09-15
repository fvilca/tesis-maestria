cmake_minimum_required(VERSION 2.8)

PROJECT(ocv_vtk)

find_package( OpenCV REQUIRED )
find_package( VTK REQUIRED)
include(${VTK_USE_FILE})

add_executable(ocv_vtk MACOSX_BUNDLE main.cpp )

target_link_libraries( ocv_vtk ${VTK_LIBRARIES})
target_link_libraries( ocv_vtk ${OpenCV_LIBS} )
