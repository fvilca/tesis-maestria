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
CMAKE_SOURCE_DIR = /home/fil/Documentos/caffe_pruebas

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fil/Documentos/caffe_pruebas/build

# Include any dependencies generated for this target.
include CMakeFiles/caffe_pruebas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/caffe_pruebas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/caffe_pruebas.dir/flags.make

CMakeFiles/caffe_pruebas.dir/main.cpp.o: CMakeFiles/caffe_pruebas.dir/flags.make
CMakeFiles/caffe_pruebas.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fil/Documentos/caffe_pruebas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/caffe_pruebas.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/caffe_pruebas.dir/main.cpp.o -c /home/fil/Documentos/caffe_pruebas/main.cpp

CMakeFiles/caffe_pruebas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/caffe_pruebas.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fil/Documentos/caffe_pruebas/main.cpp > CMakeFiles/caffe_pruebas.dir/main.cpp.i

CMakeFiles/caffe_pruebas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/caffe_pruebas.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fil/Documentos/caffe_pruebas/main.cpp -o CMakeFiles/caffe_pruebas.dir/main.cpp.s

CMakeFiles/caffe_pruebas.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/caffe_pruebas.dir/main.cpp.o.requires

CMakeFiles/caffe_pruebas.dir/main.cpp.o.provides: CMakeFiles/caffe_pruebas.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/caffe_pruebas.dir/build.make CMakeFiles/caffe_pruebas.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/caffe_pruebas.dir/main.cpp.o.provides

CMakeFiles/caffe_pruebas.dir/main.cpp.o.provides.build: CMakeFiles/caffe_pruebas.dir/main.cpp.o


# Object files for target caffe_pruebas
caffe_pruebas_OBJECTS = \
"CMakeFiles/caffe_pruebas.dir/main.cpp.o"

# External object files for target caffe_pruebas
caffe_pruebas_EXTERNAL_OBJECTS =

caffe_pruebas: CMakeFiles/caffe_pruebas.dir/main.cpp.o
caffe_pruebas: CMakeFiles/caffe_pruebas.dir/build.make
caffe_pruebas: /home/fil/Documentos/bilateralinceptions2/build/bin/lib/libcaffe.so.1.0.0-rc3
caffe_pruebas: /home/fil/Documentos/bilateralinceptions2/build/bin/lib/libproto.a
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_system.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_thread.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libglog.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libgflags.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libprotobuf.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libglog.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libgflags.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libprotobuf.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libhdf5_cpp.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libpthread.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libsz.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libz.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libdl.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libm.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libhdf5_hl_cpp.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/liblmdb.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libleveldb.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libsnappy.so
caffe_pruebas: /usr/local/cuda-8.0/lib64/libcudart.so
caffe_pruebas: /usr/local/cuda-8.0/lib64/libcurand.so
caffe_pruebas: /usr/local/cuda-8.0/lib64/libcublas.so
caffe_pruebas: /usr/local/cuda-8.0/lib64/libcublas_device.a
caffe_pruebas: /usr/local/cuda-8.0/lib64/libcudnn.so
caffe_pruebas: /usr/local/lib/libopencv_highgui.so.3.2.0
caffe_pruebas: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
caffe_pruebas: /usr/local/lib/libopencv_imgproc.so.3.2.0
caffe_pruebas: /usr/local/lib/libopencv_core.so.3.2.0
caffe_pruebas: /usr/local/lib/libopencv_cudev.so.3.2.0
caffe_pruebas: /usr/lib/liblapack.so
caffe_pruebas: /usr/lib/libcblas.so
caffe_pruebas: /usr/lib/libatlas.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libpython2.7.so
caffe_pruebas: /usr/lib/x86_64-linux-gnu/libboost_python.so
caffe_pruebas: CMakeFiles/caffe_pruebas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fil/Documentos/caffe_pruebas/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable caffe_pruebas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caffe_pruebas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/caffe_pruebas.dir/build: caffe_pruebas

.PHONY : CMakeFiles/caffe_pruebas.dir/build

CMakeFiles/caffe_pruebas.dir/requires: CMakeFiles/caffe_pruebas.dir/main.cpp.o.requires

.PHONY : CMakeFiles/caffe_pruebas.dir/requires

CMakeFiles/caffe_pruebas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/caffe_pruebas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/caffe_pruebas.dir/clean

CMakeFiles/caffe_pruebas.dir/depend:
	cd /home/fil/Documentos/caffe_pruebas/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fil/Documentos/caffe_pruebas /home/fil/Documentos/caffe_pruebas /home/fil/Documentos/caffe_pruebas/build /home/fil/Documentos/caffe_pruebas/build /home/fil/Documentos/caffe_pruebas/build/CMakeFiles/caffe_pruebas.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/caffe_pruebas.dir/depend

