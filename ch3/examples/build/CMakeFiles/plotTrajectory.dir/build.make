# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xavier/slambook2/ch3/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xavier/slambook2/ch3/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/plotTrajectory.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/plotTrajectory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/plotTrajectory.dir/flags.make

CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o: CMakeFiles/plotTrajectory.dir/flags.make
CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o: ../plotTrajectory.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xavier/slambook2/ch3/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o -c /home/xavier/slambook2/ch3/examples/plotTrajectory.cpp

CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xavier/slambook2/ch3/examples/plotTrajectory.cpp > CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.i

CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xavier/slambook2/ch3/examples/plotTrajectory.cpp -o CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.s

# Object files for target plotTrajectory
plotTrajectory_OBJECTS = \
"CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o"

# External object files for target plotTrajectory
plotTrajectory_EXTERNAL_OBJECTS =

plotTrajectory: CMakeFiles/plotTrajectory.dir/plotTrajectory.cpp.o
plotTrajectory: CMakeFiles/plotTrajectory.dir/build.make
plotTrajectory: /home/xavier/Pangolin/build/src/libpangolin.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libOpenGL.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLX.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLU.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLEW.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libEGL.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libSM.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libICE.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libX11.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libXext.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libOpenGL.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLX.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLU.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libGLEW.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libEGL.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libSM.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libICE.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libX11.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libXext.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libdc1394.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libavcodec.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libavformat.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libavutil.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libswscale.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libavdevice.so
plotTrajectory: /usr/lib/libOpenNI.so
plotTrajectory: /usr/lib/libOpenNI2.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libpng.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libz.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libjpeg.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libtiff.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libIlmImf.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/libzstd.so
plotTrajectory: /usr/lib/x86_64-linux-gnu/liblz4.so
plotTrajectory: CMakeFiles/plotTrajectory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xavier/slambook2/ch3/examples/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable plotTrajectory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/plotTrajectory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/plotTrajectory.dir/build: plotTrajectory

.PHONY : CMakeFiles/plotTrajectory.dir/build

CMakeFiles/plotTrajectory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/plotTrajectory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/plotTrajectory.dir/clean

CMakeFiles/plotTrajectory.dir/depend:
	cd /home/xavier/slambook2/ch3/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xavier/slambook2/ch3/examples /home/xavier/slambook2/ch3/examples /home/xavier/slambook2/ch3/examples/build /home/xavier/slambook2/ch3/examples/build /home/xavier/slambook2/ch3/examples/build/CMakeFiles/plotTrajectory.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/plotTrajectory.dir/depend
