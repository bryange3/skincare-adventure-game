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

# Include any dependencies generated for this target.
include _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/depend.make

# Include the progress variables for this target.
include _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/flags.make

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/flags.make
_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o: _deps/gflags-src/src/gflags.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o -c /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags.cc

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.i"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags.cc > CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.i

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.s"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags.cc -o CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.s

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/flags.make
_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o: _deps/gflags-src/src/gflags_reporting.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o -c /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_reporting.cc

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.i"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_reporting.cc > CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.i

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.s"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_reporting.cc -o CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.s

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/flags.make
_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o: _deps/gflags-src/src/gflags_completions.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o -c /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_completions.cc

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.i"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_completions.cc > CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.i

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.s"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src/src/gflags_completions.cc -o CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.s

# Object files for target gflags_nothreads_static
gflags_nothreads_static_OBJECTS = \
"CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o" \
"CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o" \
"CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o"

# External object files for target gflags_nothreads_static
gflags_nothreads_static_EXTERNAL_OBJECTS =

_deps/gflags-build/libgflags_nothreads_debug.a: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags.cc.o
_deps/gflags-build/libgflags_nothreads_debug.a: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_reporting.cc.o
_deps/gflags-build/libgflags_nothreads_debug.a: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/src/gflags_completions.cc.o
_deps/gflags-build/libgflags_nothreads_debug.a: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/build.make
_deps/gflags-build/libgflags_nothreads_debug.a: _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgflags_nothreads_debug.a"
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && $(CMAKE_COMMAND) -P CMakeFiles/gflags_nothreads_static.dir/cmake_clean_target.cmake
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gflags_nothreads_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/build: _deps/gflags-build/libgflags_nothreads_debug.a

.PHONY : _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/build

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/clean:
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build && $(CMAKE_COMMAND) -P CMakeFiles/gflags_nothreads_static.dir/cmake_clean.cmake
.PHONY : _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/clean

_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/depend:
	cd /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3 /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-src /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build /Users/bryange/Documents/CS126/Cinder/my-projects/final-project-bryange3/cmake-build-debug/_deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/gflags-build/CMakeFiles/gflags_nothreads_static.dir/depend
