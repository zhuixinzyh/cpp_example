# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /tools/Xilinx/Vitis/2023.1/tps/lnx64/cmake-3.3.2/bin/cmake

# The command to remove a file.
RM = /tools/Xilinx/Vitis/2023.1/tps/lnx64/cmake-3.3.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zyh/work/cpro/test_cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zyh/work/cpro/test_cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/main.c.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyh/work/cpro/test_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hello.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hello.dir/main.c.o   -c /home/zyh/work/cpro/test_cmake/main.c

CMakeFiles/hello.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/zyh/work/cpro/test_cmake/main.c > CMakeFiles/hello.dir/main.c.i

CMakeFiles/hello.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/zyh/work/cpro/test_cmake/main.c -o CMakeFiles/hello.dir/main.c.s

CMakeFiles/hello.dir/main.c.o.requires:

.PHONY : CMakeFiles/hello.dir/main.c.o.requires

CMakeFiles/hello.dir/main.c.o.provides: CMakeFiles/hello.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/hello.dir/build.make CMakeFiles/hello.dir/main.c.o.provides.build
.PHONY : CMakeFiles/hello.dir/main.c.o.provides

CMakeFiles/hello.dir/main.c.o.provides.build: CMakeFiles/hello.dir/main.c.o


CMakeFiles/hello.dir/hello.c.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/hello.c.o: ../hello.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zyh/work/cpro/test_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hello.dir/hello.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/hello.dir/hello.c.o   -c /home/zyh/work/cpro/test_cmake/hello.c

CMakeFiles/hello.dir/hello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hello.dir/hello.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/zyh/work/cpro/test_cmake/hello.c > CMakeFiles/hello.dir/hello.c.i

CMakeFiles/hello.dir/hello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hello.dir/hello.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/zyh/work/cpro/test_cmake/hello.c -o CMakeFiles/hello.dir/hello.c.s

CMakeFiles/hello.dir/hello.c.o.requires:

.PHONY : CMakeFiles/hello.dir/hello.c.o.requires

CMakeFiles/hello.dir/hello.c.o.provides: CMakeFiles/hello.dir/hello.c.o.requires
	$(MAKE) -f CMakeFiles/hello.dir/build.make CMakeFiles/hello.dir/hello.c.o.provides.build
.PHONY : CMakeFiles/hello.dir/hello.c.o.provides

CMakeFiles/hello.dir/hello.c.o.provides.build: CMakeFiles/hello.dir/hello.c.o


# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/main.c.o" \
"CMakeFiles/hello.dir/hello.c.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

hello: CMakeFiles/hello.dir/main.c.o
hello: CMakeFiles/hello.dir/hello.c.o
hello: CMakeFiles/hello.dir/build.make
hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zyh/work/cpro/test_cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: hello

.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/requires: CMakeFiles/hello.dir/main.c.o.requires
CMakeFiles/hello.dir/requires: CMakeFiles/hello.dir/hello.c.o.requires

.PHONY : CMakeFiles/hello.dir/requires

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/zyh/work/cpro/test_cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zyh/work/cpro/test_cmake /home/zyh/work/cpro/test_cmake /home/zyh/work/cpro/test_cmake/build /home/zyh/work/cpro/test_cmake/build /home/zyh/work/cpro/test_cmake/build/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

