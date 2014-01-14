# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/armuser/ros/rosbuild_src/v4r_libraries

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/armuser/ros/rosbuild_src/v4r_libraries/build

# Include any dependencies generated for this target.
include v4r/armarker/examples/CMakeFiles/armarker_pose.dir/depend.make

# Include the progress variables for this target.
include v4r/armarker/examples/CMakeFiles/armarker_pose.dir/progress.make

# Include the compile flags for this target's objects.
include v4r/armarker/examples/CMakeFiles/armarker_pose.dir/flags.make

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/flags.make
v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o: ../v4r/armarker/examples/main_marker_pose.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/armuser/ros/rosbuild_src/v4r_libraries/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o"
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o -c /home/armuser/ros/rosbuild_src/v4r_libraries/v4r/armarker/examples/main_marker_pose.cpp

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.i"
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/armuser/ros/rosbuild_src/v4r_libraries/v4r/armarker/examples/main_marker_pose.cpp > CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.i

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.s"
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/armuser/ros/rosbuild_src/v4r_libraries/v4r/armarker/examples/main_marker_pose.cpp -o CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.s

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.requires:
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.requires

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.provides: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.requires
	$(MAKE) -f v4r/armarker/examples/CMakeFiles/armarker_pose.dir/build.make v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.provides.build
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.provides

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.provides.build: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o

# Object files for target armarker_pose
armarker_pose_OBJECTS = \
"CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o"

# External object files for target armarker_pose
armarker_pose_EXTERNAL_OBJECTS =

../bin/armarker_pose: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o
../bin/armarker_pose: ../lib/libv4rmarker.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_calib3d.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_contrib.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_core.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_features2d.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_flann.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_gpu.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_highgui.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_imgproc.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_legacy.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_ml.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_nonfree.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_objdetect.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_photo.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_stitching.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_superres.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_video.so
../bin/armarker_pose: /opt/ros/groovy/lib/libopencv_videostab.so
../bin/armarker_pose: ../lib/libar.a
../bin/armarker_pose: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/build.make
../bin/armarker_pose: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../../bin/armarker_pose"
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/armarker_pose.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
v4r/armarker/examples/CMakeFiles/armarker_pose.dir/build: ../bin/armarker_pose
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/build

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/requires: v4r/armarker/examples/CMakeFiles/armarker_pose.dir/main_marker_pose.cpp.o.requires
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/requires

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/clean:
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples && $(CMAKE_COMMAND) -P CMakeFiles/armarker_pose.dir/cmake_clean.cmake
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/clean

v4r/armarker/examples/CMakeFiles/armarker_pose.dir/depend:
	cd /home/armuser/ros/rosbuild_src/v4r_libraries/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/armuser/ros/rosbuild_src/v4r_libraries /home/armuser/ros/rosbuild_src/v4r_libraries/v4r/armarker/examples /home/armuser/ros/rosbuild_src/v4r_libraries/build /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples /home/armuser/ros/rosbuild_src/v4r_libraries/build/v4r/armarker/examples/CMakeFiles/armarker_pose.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : v4r/armarker/examples/CMakeFiles/armarker_pose.dir/depend

