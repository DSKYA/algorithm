# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/cxj/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/cxj/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cxj/algorithm/wangyi1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cxj/algorithm/wangyi1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/wangyi1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wangyi1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wangyi1.dir/flags.make

CMakeFiles/wangyi1.dir/main.cpp.o: CMakeFiles/wangyi1.dir/flags.make
CMakeFiles/wangyi1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cxj/algorithm/wangyi1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wangyi1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wangyi1.dir/main.cpp.o -c /home/cxj/algorithm/wangyi1/main.cpp

CMakeFiles/wangyi1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wangyi1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cxj/algorithm/wangyi1/main.cpp > CMakeFiles/wangyi1.dir/main.cpp.i

CMakeFiles/wangyi1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wangyi1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cxj/algorithm/wangyi1/main.cpp -o CMakeFiles/wangyi1.dir/main.cpp.s

CMakeFiles/wangyi1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/wangyi1.dir/main.cpp.o.requires

CMakeFiles/wangyi1.dir/main.cpp.o.provides: CMakeFiles/wangyi1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/wangyi1.dir/build.make CMakeFiles/wangyi1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/wangyi1.dir/main.cpp.o.provides

CMakeFiles/wangyi1.dir/main.cpp.o.provides.build: CMakeFiles/wangyi1.dir/main.cpp.o


# Object files for target wangyi1
wangyi1_OBJECTS = \
"CMakeFiles/wangyi1.dir/main.cpp.o"

# External object files for target wangyi1
wangyi1_EXTERNAL_OBJECTS =

wangyi1: CMakeFiles/wangyi1.dir/main.cpp.o
wangyi1: CMakeFiles/wangyi1.dir/build.make
wangyi1: CMakeFiles/wangyi1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cxj/algorithm/wangyi1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable wangyi1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wangyi1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wangyi1.dir/build: wangyi1

.PHONY : CMakeFiles/wangyi1.dir/build

CMakeFiles/wangyi1.dir/requires: CMakeFiles/wangyi1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/wangyi1.dir/requires

CMakeFiles/wangyi1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wangyi1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wangyi1.dir/clean

CMakeFiles/wangyi1.dir/depend:
	cd /home/cxj/algorithm/wangyi1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cxj/algorithm/wangyi1 /home/cxj/algorithm/wangyi1 /home/cxj/algorithm/wangyi1/cmake-build-debug /home/cxj/algorithm/wangyi1/cmake-build-debug /home/cxj/algorithm/wangyi1/cmake-build-debug/CMakeFiles/wangyi1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wangyi1.dir/depend

