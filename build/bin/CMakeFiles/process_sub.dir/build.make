# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/susu1970/susu1970/zaza/practice/cpp/process_manager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/process_sub.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/process_sub.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/process_sub.dir/flags.make

bin/CMakeFiles/process_sub.dir/process_sub.cc.o: bin/CMakeFiles/process_sub.dir/flags.make
bin/CMakeFiles/process_sub.dir/process_sub.cc.o: ../src/process_sub.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/process_sub.dir/process_sub.cc.o"
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/process_sub.dir/process_sub.cc.o -c /home/susu1970/susu1970/zaza/practice/cpp/process_manager/src/process_sub.cc

bin/CMakeFiles/process_sub.dir/process_sub.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/process_sub.dir/process_sub.cc.i"
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/susu1970/susu1970/zaza/practice/cpp/process_manager/src/process_sub.cc > CMakeFiles/process_sub.dir/process_sub.cc.i

bin/CMakeFiles/process_sub.dir/process_sub.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/process_sub.dir/process_sub.cc.s"
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/susu1970/susu1970/zaza/practice/cpp/process_manager/src/process_sub.cc -o CMakeFiles/process_sub.dir/process_sub.cc.s

# Object files for target process_sub
process_sub_OBJECTS = \
"CMakeFiles/process_sub.dir/process_sub.cc.o"

# External object files for target process_sub
process_sub_EXTERNAL_OBJECTS =

bin/process_sub: bin/CMakeFiles/process_sub.dir/process_sub.cc.o
bin/process_sub: bin/CMakeFiles/process_sub.dir/build.make
bin/process_sub: bin/CMakeFiles/process_sub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable process_sub"
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/process_sub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/process_sub.dir/build: bin/process_sub

.PHONY : bin/CMakeFiles/process_sub.dir/build

bin/CMakeFiles/process_sub.dir/clean:
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/process_sub.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/process_sub.dir/clean

bin/CMakeFiles/process_sub.dir/depend:
	cd /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/susu1970/susu1970/zaza/practice/cpp/process_manager /home/susu1970/susu1970/zaza/practice/cpp/process_manager/src /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin /home/susu1970/susu1970/zaza/practice/cpp/process_manager/build/bin/CMakeFiles/process_sub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/process_sub.dir/depend

