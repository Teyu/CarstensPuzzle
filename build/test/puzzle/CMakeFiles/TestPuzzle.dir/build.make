# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/julia/Documents/carstens_puzzle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julia/Documents/carstens_puzzle/build

# Include any dependencies generated for this target.
include test/puzzle/CMakeFiles/TestPuzzle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/puzzle/CMakeFiles/TestPuzzle.dir/compiler_depend.make

# Include the progress variables for this target.
include test/puzzle/CMakeFiles/TestPuzzle.dir/progress.make

# Include the compile flags for this target's objects.
include test/puzzle/CMakeFiles/TestPuzzle.dir/flags.make

test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o: test/puzzle/CMakeFiles/TestPuzzle.dir/flags.make
test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o: /home/julia/Documents/carstens_puzzle/test/puzzle/PuzzleTest.cpp
test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o: test/puzzle/CMakeFiles/TestPuzzle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julia/Documents/carstens_puzzle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o -MF CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o.d -o CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o -c /home/julia/Documents/carstens_puzzle/test/puzzle/PuzzleTest.cpp

test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.i"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julia/Documents/carstens_puzzle/test/puzzle/PuzzleTest.cpp > CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.i

test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.s"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julia/Documents/carstens_puzzle/test/puzzle/PuzzleTest.cpp -o CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.s

test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o: test/puzzle/CMakeFiles/TestPuzzle.dir/flags.make
test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o: /home/julia/Documents/carstens_puzzle/src/Randomizer.cpp
test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o: test/puzzle/CMakeFiles/TestPuzzle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/julia/Documents/carstens_puzzle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o -MF CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o.d -o CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o -c /home/julia/Documents/carstens_puzzle/src/Randomizer.cpp

test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.i"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julia/Documents/carstens_puzzle/src/Randomizer.cpp > CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.i

test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.s"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julia/Documents/carstens_puzzle/src/Randomizer.cpp -o CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.s

# Object files for target TestPuzzle
TestPuzzle_OBJECTS = \
"CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o" \
"CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o"

# External object files for target TestPuzzle
TestPuzzle_EXTERNAL_OBJECTS =

test/puzzle/TestPuzzle: test/puzzle/CMakeFiles/TestPuzzle.dir/PuzzleTest.cpp.o
test/puzzle/TestPuzzle: test/puzzle/CMakeFiles/TestPuzzle.dir/__/__/src/Randomizer.cpp.o
test/puzzle/TestPuzzle: test/puzzle/CMakeFiles/TestPuzzle.dir/build.make
test/puzzle/TestPuzzle: lib/libgtest.a
test/puzzle/TestPuzzle: lib/libgtest_main.a
test/puzzle/TestPuzzle: lib/libgmock.a
test/puzzle/TestPuzzle: lib/libgmock_main.a
test/puzzle/TestPuzzle: lib/libgmock.a
test/puzzle/TestPuzzle: lib/libgtest.a
test/puzzle/TestPuzzle: test/puzzle/CMakeFiles/TestPuzzle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/julia/Documents/carstens_puzzle/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable TestPuzzle"
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TestPuzzle.dir/link.txt --verbose=$(VERBOSE)
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && /usr/bin/cmake -D TEST_TARGET=TestPuzzle -D TEST_EXECUTABLE=/home/julia/Documents/carstens_puzzle/build/test/puzzle/TestPuzzle -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/home/julia/Documents/carstens_puzzle/build/test/puzzle -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=TestPuzzle_TESTS -D CTEST_FILE=/home/julia/Documents/carstens_puzzle/build/test/puzzle/TestPuzzle[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
test/puzzle/CMakeFiles/TestPuzzle.dir/build: test/puzzle/TestPuzzle
.PHONY : test/puzzle/CMakeFiles/TestPuzzle.dir/build

test/puzzle/CMakeFiles/TestPuzzle.dir/clean:
	cd /home/julia/Documents/carstens_puzzle/build/test/puzzle && $(CMAKE_COMMAND) -P CMakeFiles/TestPuzzle.dir/cmake_clean.cmake
.PHONY : test/puzzle/CMakeFiles/TestPuzzle.dir/clean

test/puzzle/CMakeFiles/TestPuzzle.dir/depend:
	cd /home/julia/Documents/carstens_puzzle/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julia/Documents/carstens_puzzle /home/julia/Documents/carstens_puzzle/test/puzzle /home/julia/Documents/carstens_puzzle/build /home/julia/Documents/carstens_puzzle/build/test/puzzle /home/julia/Documents/carstens_puzzle/build/test/puzzle/CMakeFiles/TestPuzzle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/puzzle/CMakeFiles/TestPuzzle.dir/depend
