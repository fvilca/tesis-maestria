# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fil/Documentos/caffe_pruebas/xor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fil/Documentos/caffe_pruebas/xor/build

# Include any dependencies generated for this target.
include CMakeFiles/testnet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testnet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testnet.dir/flags.make

CMakeFiles/testnet.dir/test.cpp.o: CMakeFiles/testnet.dir/flags.make
CMakeFiles/testnet.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fil/Documentos/caffe_pruebas/xor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testnet.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testnet.dir/test.cpp.o -c /home/fil/Documentos/caffe_pruebas/xor/test.cpp

CMakeFiles/testnet.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testnet.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fil/Documentos/caffe_pruebas/xor/test.cpp > CMakeFiles/testnet.dir/test.cpp.i

CMakeFiles/testnet.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testnet.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fil/Documentos/caffe_pruebas/xor/test.cpp -o CMakeFiles/testnet.dir/test.cpp.s

CMakeFiles/testnet.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/testnet.dir/test.cpp.o.requires

CMakeFiles/testnet.dir/test.cpp.o.provides: CMakeFiles/testnet.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/testnet.dir/build.make CMakeFiles/testnet.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/testnet.dir/test.cpp.o.provides

CMakeFiles/testnet.dir/test.cpp.o.provides.build: CMakeFiles/testnet.dir/test.cpp.o


# Object files for target testnet
testnet_OBJECTS = \
"CMakeFiles/testnet.dir/test.cpp.o"

# External object files for target testnet
testnet_EXTERNAL_OBJECTS =

testnet: CMakeFiles/testnet.dir/test.cpp.o
testnet: CMakeFiles/testnet.dir/build.make
testnet: /home/fil/Documentos/bilateralinceptions2/build/bin/lib/libcaffe.so.1.0.0-rc3
testnet: /home/fil/Documentos/bilateralinceptions2/build/bin/lib/libproto.a
testnet: /usr/lib/x86_64-linux-gnu/libboost_system.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_thread.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
testnet: /usr/lib/x86_64-linux-gnu/libglog.so
testnet: /usr/lib/x86_64-linux-gnu/libgflags.so
testnet: /usr/lib/x86_64-linux-gnu/libprotobuf.so
testnet: /usr/lib/x86_64-linux-gnu/libglog.so
testnet: /usr/lib/x86_64-linux-gnu/libgflags.so
testnet: /usr/lib/x86_64-linux-gnu/libprotobuf.so
testnet: /usr/lib/x86_64-linux-gnu/libhdf5_cpp.so
testnet: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
testnet: /usr/lib/x86_64-linux-gnu/libpthread.so
testnet: /usr/lib/x86_64-linux-gnu/libsz.so
testnet: /usr/lib/x86_64-linux-gnu/libz.so
testnet: /usr/lib/x86_64-linux-gnu/libdl.so
testnet: /usr/lib/x86_64-linux-gnu/libm.so
testnet: /usr/lib/x86_64-linux-gnu/libhdf5_hl_cpp.so
testnet: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.so
testnet: /usr/lib/x86_64-linux-gnu/liblmdb.so
testnet: /usr/lib/x86_64-linux-gnu/libleveldb.so
testnet: /usr/lib/x86_64-linux-gnu/libsnappy.so
testnet: /usr/local/cuda-8.0/lib64/libcudart.so
testnet: /usr/local/cuda-8.0/lib64/libcurand.so
testnet: /usr/local/cuda-8.0/lib64/libcublas.so
testnet: /usr/local/cuda-8.0/lib64/libcublas_device.a
testnet: /usr/local/cuda-8.0/lib64/libcudnn.so
testnet: /usr/local/lib/libopencv_highgui.so.3.2.0
testnet: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
testnet: /usr/local/lib/libopencv_imgproc.so.3.2.0
testnet: /usr/local/lib/libopencv_core.so.3.2.0
testnet: /usr/local/lib/libopencv_cudev.so.3.2.0
testnet: /usr/lib/liblapack.so
testnet: /usr/lib/libcblas.so
testnet: /usr/lib/libatlas.so
testnet: /usr/lib/x86_64-linux-gnu/libpython2.7.so
testnet: /usr/lib/x86_64-linux-gnu/libboost_python.so
testnet: CMakeFiles/testnet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fil/Documentos/caffe_pruebas/xor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testnet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testnet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testnet.dir/build: testnet

.PHONY : CMakeFiles/testnet.dir/build

CMakeFiles/testnet.dir/requires: CMakeFiles/testnet.dir/test.cpp.o.requires

.PHONY : CMakeFiles/testnet.dir/requires

CMakeFiles/testnet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testnet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testnet.dir/clean

CMakeFiles/testnet.dir/depend:
	cd /home/fil/Documentos/caffe_pruebas/xor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fil/Documentos/caffe_pruebas/xor /home/fil/Documentos/caffe_pruebas/xor /home/fil/Documentos/caffe_pruebas/xor/build /home/fil/Documentos/caffe_pruebas/xor/build /home/fil/Documentos/caffe_pruebas/xor/build/CMakeFiles/testnet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testnet.dir/depend
