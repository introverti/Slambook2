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
CMAKE_SOURCE_DIR = /home/xavier/slambook2/ch4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xavier/slambook2/ch4/build

# Include any dependencies generated for this target.
include useSophus/CMakeFiles/useSophus.dir/depend.make

# Include the progress variables for this target.
include useSophus/CMakeFiles/useSophus.dir/progress.make

# Include the compile flags for this target's objects.
include useSophus/CMakeFiles/useSophus.dir/flags.make

useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.o: useSophus/CMakeFiles/useSophus.dir/flags.make
useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.o: ../useSophus/useSophus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xavier/slambook2/ch4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.o"
	cd /home/xavier/slambook2/ch4/build/useSophus && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/useSophus.dir/useSophus.cpp.o -c /home/xavier/slambook2/ch4/useSophus/useSophus.cpp

useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/useSophus.dir/useSophus.cpp.i"
	cd /home/xavier/slambook2/ch4/build/useSophus && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xavier/slambook2/ch4/useSophus/useSophus.cpp > CMakeFiles/useSophus.dir/useSophus.cpp.i

useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/useSophus.dir/useSophus.cpp.s"
	cd /home/xavier/slambook2/ch4/build/useSophus && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xavier/slambook2/ch4/useSophus/useSophus.cpp -o CMakeFiles/useSophus.dir/useSophus.cpp.s

# Object files for target useSophus
useSophus_OBJECTS = \
"CMakeFiles/useSophus.dir/useSophus.cpp.o"

# External object files for target useSophus
useSophus_EXTERNAL_OBJECTS =

useSophus/useSophus: useSophus/CMakeFiles/useSophus.dir/useSophus.cpp.o
useSophus/useSophus: useSophus/CMakeFiles/useSophus.dir/build.make
useSophus/useSophus: useSophus/CMakeFiles/useSophus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xavier/slambook2/ch4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable useSophus"
	cd /home/xavier/slambook2/ch4/build/useSophus && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/useSophus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
useSophus/CMakeFiles/useSophus.dir/build: useSophus/useSophus

.PHONY : useSophus/CMakeFiles/useSophus.dir/build

useSophus/CMakeFiles/useSophus.dir/clean:
	cd /home/xavier/slambook2/ch4/build/useSophus && $(CMAKE_COMMAND) -P CMakeFiles/useSophus.dir/cmake_clean.cmake
.PHONY : useSophus/CMakeFiles/useSophus.dir/clean

useSophus/CMakeFiles/useSophus.dir/depend:
	cd /home/xavier/slambook2/ch4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xavier/slambook2/ch4 /home/xavier/slambook2/ch4/useSophus /home/xavier/slambook2/ch4/build /home/xavier/slambook2/ch4/build/useSophus /home/xavier/slambook2/ch4/build/useSophus/CMakeFiles/useSophus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : useSophus/CMakeFiles/useSophus.dir/depend
