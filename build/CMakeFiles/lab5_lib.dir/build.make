# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\gitprojects\tp-lab-5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\gitprojects\tp-lab-5\build

# Include any dependencies generated for this target.
include CMakeFiles/lab5_lib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab5_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab5_lib.dir/flags.make

CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj: CMakeFiles/lab5_lib.dir/flags.make
CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj: CMakeFiles/lab5_lib.dir/includes_CXX.rsp
CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj: ../src/lab5_lib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\gitprojects\tp-lab-5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj"
	"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab5_lib.dir\src\lab5_lib.cpp.obj -c D:\gitprojects\tp-lab-5\src\lab5_lib.cpp

CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.i"
	"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\gitprojects\tp-lab-5\src\lab5_lib.cpp > CMakeFiles\lab5_lib.dir\src\lab5_lib.cpp.i

CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.s"
	"C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\gitprojects\tp-lab-5\src\lab5_lib.cpp -o CMakeFiles\lab5_lib.dir\src\lab5_lib.cpp.s

# Object files for target lab5_lib
lab5_lib_OBJECTS = \
"CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj"

# External object files for target lab5_lib
lab5_lib_EXTERNAL_OBJECTS =

liblab5_lib.a: CMakeFiles/lab5_lib.dir/src/lab5_lib.cpp.obj
liblab5_lib.a: CMakeFiles/lab5_lib.dir/build.make
liblab5_lib.a: CMakeFiles/lab5_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\gitprojects\tp-lab-5\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblab5_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles\lab5_lib.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab5_lib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab5_lib.dir/build: liblab5_lib.a

.PHONY : CMakeFiles/lab5_lib.dir/build

CMakeFiles/lab5_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab5_lib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab5_lib.dir/clean

CMakeFiles/lab5_lib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\gitprojects\tp-lab-5 D:\gitprojects\tp-lab-5 D:\gitprojects\tp-lab-5\build D:\gitprojects\tp-lab-5\build D:\gitprojects\tp-lab-5\build\CMakeFiles\lab5_lib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab5_lib.dir/depend

