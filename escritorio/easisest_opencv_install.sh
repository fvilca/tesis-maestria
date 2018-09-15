######################################
# INSTALL OPENCV ON UBUNTU OR DEBIAN #
# SCRIPT FROM PYTHONOPENCV.COM
######################################

# |         THIS SCRIPT IS TESTED CORRECTLY ON         |
# |----------------------------------------------------|
# | OS             | OpenCV       | Test | Last test   |
# |----------------|--------------|------|-------------|
# | Ubuntu 16.04.2 | OpenCV 3.2.0 | OK   | 20 May 2017 |
# | Debian 8.8     | OpenCV 3.2.0 | OK   | 20 May 2017 |
# | Debian 9.0     | OpenCV 3.2.0 | OK   | 25 Jun 2017 |

# 1. KEEP UBUNTU OR DEBIAN UP TO DATE

#sudo apt-get -y update
#sudo apt-get -y upgrade
#sudo apt-get -y dist-upgrade
#sudo apt-get -y autoremove


# 2. INSTALL THE DEPENDENCIES

# Build tools:
#sudo apt-get install -y build-essential cmake pkg-config

# GUI (if you want to use GTK instead of Qt, replace 'qt5-default' with 'libgtkglext1-dev' and remove '-DWITH_QT=ON' option in CMake):
#sudo apt-get install -y qt5-default libvtk6-dev

# Media I/O:
#sudo apt-get install -y zlib1g-dev libjpeg-dev libwebp-dev libpng-dev libtiff5-dev libjasper-dev libopenexr-dev libgdal-dev

# Video I/O:
#sudo apt-get install -y libdc1394-22-dev libavcodec-dev libavformat-dev libswscale-dev libtheora-dev libvorbis-dev libxvidcore-dev libx264-dev yasm libopencore-amrnb-dev libopencore-amrwb-dev libv4l-dev libxine2-dev

# Parallelism and linear algebra libraries:
# sudo apt-get install -y libtbb-dev libeigen3-dev

# Python:
# sudo apt-get install -y python-dev python-tk python-numpy python3-dev python3-tk python3-numpy



# Java:
# sudo apt-get install -y ant default-jdk

# Documentation:
# sudo apt-get install -y doxygen


# 3. INSTALL THE LIBRARY (YOU CAN CHANGE '3.2.0' FOR THE LAST STABLE VERSION)

sudo apt-get install -y unzip wget
wget https://github.com/opencv/opencv/archive/3.2.0.zip
unzip 3.2.0.zip
rm 3.2.0.zip
mv opencv-3.2.0 OpenCV

wget https://github.com/opencv/opencv_contrib/archive/3.2.0.zip
unzip 3.2.0.zip
mv opencv_contrib-3.2.0 OpenCV

cd OpenCV
mkdir build
cd build
cmake -DWITH_QT=ON -DWITH_OPENGL=ON -DFORCE_VTK=ON -DWITH_TBB=ON -DWITH_GDAL=ON -DWITH_XINE=ON -DBUILD_EXAMPLES=ON -DENABLE_PRECOMPILED_HEADERS=OFF -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local -DOPENCV_EXTRA_MODULES_PATH=/home/fil/OpenCV/opencv_contrib-3.2.0/modules -D WITH_CUDA=ON -D WITH_CUBLAS=ON -D WITH_V4L=ON -D WITH_QT=ON -DCUDA_NVCC_FLAGS="-D_FORCE_INLINES" -D WITH_VTK=ON -D BUILD_NEW_PYTHON_SUPPORT=ON -D WITH_V4L=ON -D INSTALL_C_EXAMPLES=ON -D INSTALL_PYTHON_EXAMPLES=ON -D BUILD_EXAMPLES=ON -D PYTHON_EXECUTABLE=/usr/bin/python

make -j4
sudo make install
sudo ldconfig


#Now to check if OpenCV is installed on a machine, run the following commands
pkg-config --modversion opencv


#http://www.samontab.com/web/2017/06/installing-opencv-3-2-0-with-contrib-modules-in-ubuntu-16-04-lts/
#https://github.com/milq/milq/tree/master/scripts/bash
#http://sketchingdream.com/blog/cuda-enabled-opencv-3-3-0-installation-on-ubuntu-16-04/
#http://www.codebind.com/cpp-tutorial/install-opencv-ubuntu-cpp/
#http://remananr.com/Blog/opencv-in-python3/
#https://github.com/raghudeep/bilateralinceptions
