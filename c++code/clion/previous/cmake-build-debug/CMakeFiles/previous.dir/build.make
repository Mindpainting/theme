# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Clion workspace\previous"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Clion workspace\previous\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/previous.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/previous.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/previous.dir/flags.make

CMakeFiles/previous.dir/main.cpp.obj: CMakeFiles/previous.dir/flags.make
CMakeFiles/previous.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Clion workspace\previous\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/previous.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\previous.dir\main.cpp.obj -c "E:\Clion workspace\previous\main.cpp"

CMakeFiles/previous.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/previous.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Clion workspace\previous\main.cpp" > CMakeFiles\previous.dir\main.cpp.i

CMakeFiles/previous.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/previous.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Clion workspace\previous\main.cpp" -o CMakeFiles\previous.dir\main.cpp.s

# Object files for target previous
previous_OBJECTS = \
"CMakeFiles/previous.dir/main.cpp.obj"

# External object files for target previous
previous_EXTERNAL_OBJECTS =

previous.exe: CMakeFiles/previous.dir/main.cpp.obj
previous.exe: CMakeFiles/previous.dir/build.make
previous.exe: CMakeFiles/previous.dir/linklibs.rsp
previous.exe: CMakeFiles/previous.dir/objects1.rsp
previous.exe: CMakeFiles/previous.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Clion workspace\previous\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable previous.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\previous.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/previous.dir/build: previous.exe
.PHONY : CMakeFiles/previous.dir/build

CMakeFiles/previous.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\previous.dir\cmake_clean.cmake
.PHONY : CMakeFiles/previous.dir/clean

CMakeFiles/previous.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Clion workspace\previous" "E:\Clion workspace\previous" "E:\Clion workspace\previous\cmake-build-debug" "E:\Clion workspace\previous\cmake-build-debug" "E:\Clion workspace\previous\cmake-build-debug\CMakeFiles\previous.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/previous.dir/depend
