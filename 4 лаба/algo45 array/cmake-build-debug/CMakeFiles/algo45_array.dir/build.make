# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "/Users/arsenijkarpov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/arsenijkarpov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/algo45_array.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algo45_array.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algo45_array.dir/flags.make

CMakeFiles/algo45_array.dir/main.cpp.o: CMakeFiles/algo45_array.dir/flags.make
CMakeFiles/algo45_array.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algo45_array.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algo45_array.dir/main.cpp.o -c "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/main.cpp"

CMakeFiles/algo45_array.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algo45_array.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/main.cpp" > CMakeFiles/algo45_array.dir/main.cpp.i

CMakeFiles/algo45_array.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algo45_array.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/main.cpp" -o CMakeFiles/algo45_array.dir/main.cpp.s

# Object files for target algo45_array
algo45_array_OBJECTS = \
"CMakeFiles/algo45_array.dir/main.cpp.o"

# External object files for target algo45_array
algo45_array_EXTERNAL_OBJECTS =

algo45_array: CMakeFiles/algo45_array.dir/main.cpp.o
algo45_array: CMakeFiles/algo45_array.dir/build.make
algo45_array: CMakeFiles/algo45_array.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algo45_array"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algo45_array.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algo45_array.dir/build: algo45_array

.PHONY : CMakeFiles/algo45_array.dir/build

CMakeFiles/algo45_array.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algo45_array.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algo45_array.dir/clean

CMakeFiles/algo45_array.dir/depend:
	cd "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array" "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array" "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug" "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug" "/Users/arsenijkarpov/1 семестр /Алгоритмы/4 лаба/algo45 array/cmake-build-debug/CMakeFiles/algo45_array.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/algo45_array.dir/depend

