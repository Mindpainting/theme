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
CMAKE_SOURCE_DIR = "E:\Clion workspace\data_structure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Clion workspace\data_structure\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/postorder_thread_binary_tree.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/postorder_thread_binary_tree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/postorder_thread_binary_tree.dir/flags.make

CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.obj: CMakeFiles/postorder_thread_binary_tree.dir/flags.make
CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.obj: ../postorder_thread_binary_tree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\Clion workspace\data_structure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.obj"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\postorder_thread_binary_tree.dir\postorder_thread_binary_tree.cpp.obj -c "E:\Clion workspace\data_structure\postorder_thread_binary_tree.cpp"

CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\Clion workspace\data_structure\postorder_thread_binary_tree.cpp" > CMakeFiles\postorder_thread_binary_tree.dir\postorder_thread_binary_tree.cpp.i

CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "E:\Clion workspace\data_structure\postorder_thread_binary_tree.cpp" -o CMakeFiles\postorder_thread_binary_tree.dir\postorder_thread_binary_tree.cpp.s

# Object files for target postorder_thread_binary_tree
postorder_thread_binary_tree_OBJECTS = \
"CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.obj"

# External object files for target postorder_thread_binary_tree
postorder_thread_binary_tree_EXTERNAL_OBJECTS =

postorder_thread_binary_tree.exe: CMakeFiles/postorder_thread_binary_tree.dir/postorder_thread_binary_tree.cpp.obj
postorder_thread_binary_tree.exe: CMakeFiles/postorder_thread_binary_tree.dir/build.make
postorder_thread_binary_tree.exe: CMakeFiles/postorder_thread_binary_tree.dir/linklibs.rsp
postorder_thread_binary_tree.exe: CMakeFiles/postorder_thread_binary_tree.dir/objects1.rsp
postorder_thread_binary_tree.exe: CMakeFiles/postorder_thread_binary_tree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\Clion workspace\data_structure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable postorder_thread_binary_tree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\postorder_thread_binary_tree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/postorder_thread_binary_tree.dir/build: postorder_thread_binary_tree.exe
.PHONY : CMakeFiles/postorder_thread_binary_tree.dir/build

CMakeFiles/postorder_thread_binary_tree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\postorder_thread_binary_tree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/postorder_thread_binary_tree.dir/clean

CMakeFiles/postorder_thread_binary_tree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\Clion workspace\data_structure" "E:\Clion workspace\data_structure" "E:\Clion workspace\data_structure\cmake-build-debug" "E:\Clion workspace\data_structure\cmake-build-debug" "E:\Clion workspace\data_structure\cmake-build-debug\CMakeFiles\postorder_thread_binary_tree.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/postorder_thread_binary_tree.dir/depend

