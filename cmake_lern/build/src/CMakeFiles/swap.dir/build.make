# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /root/lernning_file/cmake_lern

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/lernning_file/cmake_lern/build

# Include any dependencies generated for this target.
include src/CMakeFiles/swap.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/swap.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/swap.dir/flags.make

src/CMakeFiles/swap.dir/swap.cpp.o: src/CMakeFiles/swap.dir/flags.make
src/CMakeFiles/swap.dir/swap.cpp.o: ../src/swap.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/lernning_file/cmake_lern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/swap.dir/swap.cpp.o"
	cd /root/lernning_file/cmake_lern/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/swap.dir/swap.cpp.o -c /root/lernning_file/cmake_lern/src/swap.cpp

src/CMakeFiles/swap.dir/swap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/swap.dir/swap.cpp.i"
	cd /root/lernning_file/cmake_lern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/lernning_file/cmake_lern/src/swap.cpp > CMakeFiles/swap.dir/swap.cpp.i

src/CMakeFiles/swap.dir/swap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/swap.dir/swap.cpp.s"
	cd /root/lernning_file/cmake_lern/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/lernning_file/cmake_lern/src/swap.cpp -o CMakeFiles/swap.dir/swap.cpp.s

src/CMakeFiles/swap.dir/swap.cpp.o.requires:

.PHONY : src/CMakeFiles/swap.dir/swap.cpp.o.requires

src/CMakeFiles/swap.dir/swap.cpp.o.provides: src/CMakeFiles/swap.dir/swap.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/swap.dir/build.make src/CMakeFiles/swap.dir/swap.cpp.o.provides.build
.PHONY : src/CMakeFiles/swap.dir/swap.cpp.o.provides

src/CMakeFiles/swap.dir/swap.cpp.o.provides.build: src/CMakeFiles/swap.dir/swap.cpp.o


# Object files for target swap
swap_OBJECTS = \
"CMakeFiles/swap.dir/swap.cpp.o"

# External object files for target swap
swap_EXTERNAL_OBJECTS =

lib/libswap.a: src/CMakeFiles/swap.dir/swap.cpp.o
lib/libswap.a: src/CMakeFiles/swap.dir/build.make
lib/libswap.a: src/CMakeFiles/swap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/lernning_file/cmake_lern/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../lib/libswap.a"
	cd /root/lernning_file/cmake_lern/build/src && $(CMAKE_COMMAND) -P CMakeFiles/swap.dir/cmake_clean_target.cmake
	cd /root/lernning_file/cmake_lern/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/swap.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/swap.dir/build: lib/libswap.a

.PHONY : src/CMakeFiles/swap.dir/build

src/CMakeFiles/swap.dir/requires: src/CMakeFiles/swap.dir/swap.cpp.o.requires

.PHONY : src/CMakeFiles/swap.dir/requires

src/CMakeFiles/swap.dir/clean:
	cd /root/lernning_file/cmake_lern/build/src && $(CMAKE_COMMAND) -P CMakeFiles/swap.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/swap.dir/clean

src/CMakeFiles/swap.dir/depend:
	cd /root/lernning_file/cmake_lern/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/lernning_file/cmake_lern /root/lernning_file/cmake_lern/src /root/lernning_file/cmake_lern/build /root/lernning_file/cmake_lern/build/src /root/lernning_file/cmake_lern/build/src/CMakeFiles/swap.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/swap.dir/depend

