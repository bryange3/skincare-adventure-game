# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include _deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/progress.make

_deps/gflags-build/CMakeFiles/ContinuousConfigure:
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Applications/CLion.app/Contents/bin/cmake/mac/bin/ctest -D ContinuousConfigure

ContinuousConfigure: _deps/gflags-build/CMakeFiles/ContinuousConfigure
ContinuousConfigure: _deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/build.make

.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
_deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure

.PHONY : _deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/build

_deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousConfigure.dir/cmake_clean.cmake
.PHONY : _deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/clean

_deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/depend:
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3 /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/gflags-build/CMakeFiles/ContinuousConfigure.dir/depend

