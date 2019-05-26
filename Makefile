# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amajm/CS100Project/spring-2019-assignment-cs100-abdullah-emily

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amajm/CS100Project/spring-2019-assignment-cs100-abdullah-emily

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake.exe -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: install/local

.PHONY : install/local/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake.exe -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake.exe -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: install/strip

.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake.exe -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake.exe -P cmake_install.cmake
.PHONY : install/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amajm/CS100Project/spring-2019-assignment-cs100-abdullah-emily/CMakeFiles /home/amajm/CS100Project/spring-2019-assignment-cs100-abdullah-emily/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/amajm/CS100Project/spring-2019-assignment-cs100-abdullah-emily/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named rshell

# Build rule for target.
rshell: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 rshell
.PHONY : rshell

# fast build rule for target.
rshell/fast:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/build
.PHONY : rshell/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock_main.dir/build.make googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f googletest/googletest/CMakeFiles/gtest.dir/build.make googletest/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f googletest/googletest/CMakeFiles/gtest_main.dir/build.make googletest/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

src/Add.o: src/Add.cpp.o

.PHONY : src/Add.o

# target to build an object file
src/Add.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Add.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Add.cpp.o
.PHONY : src/Add.cpp.o

src/Add.i: src/Add.cpp.i

.PHONY : src/Add.i

# target to preprocess a source file
src/Add.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Add.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Add.cpp.i
.PHONY : src/Add.cpp.i

src/Add.s: src/Add.cpp.s

.PHONY : src/Add.s

# target to generate assembly for a file
src/Add.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Add.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Add.cpp.s
.PHONY : src/Add.cpp.s

src/Command.o: src/Command.cpp.o

.PHONY : src/Command.o

# target to build an object file
src/Command.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Command.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Command.cpp.o
.PHONY : src/Command.cpp.o

src/Command.i: src/Command.cpp.i

.PHONY : src/Command.i

# target to preprocess a source file
src/Command.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Command.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Command.cpp.i
.PHONY : src/Command.cpp.i

src/Command.s: src/Command.cpp.s

.PHONY : src/Command.s

# target to generate assembly for a file
src/Command.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Command.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Command.cpp.s
.PHONY : src/Command.cpp.s

src/ConstructTree.o: src/ConstructTree.cpp.o

.PHONY : src/ConstructTree.o

# target to build an object file
src/ConstructTree.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConstructTree.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConstructTree.cpp.o
.PHONY : src/ConstructTree.cpp.o

src/ConstructTree.i: src/ConstructTree.cpp.i

.PHONY : src/ConstructTree.i

# target to preprocess a source file
src/ConstructTree.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConstructTree.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConstructTree.cpp.i
.PHONY : src/ConstructTree.cpp.i

src/ConstructTree.s: src/ConstructTree.cpp.s

.PHONY : src/ConstructTree.s

# target to generate assembly for a file
src/ConstructTree.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/ConstructTree.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/ConstructTree.cpp.s
.PHONY : src/ConstructTree.cpp.s

src/Or.o: src/Or.cpp.o

.PHONY : src/Or.o

# target to build an object file
src/Or.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Or.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Or.cpp.o
.PHONY : src/Or.cpp.o

src/Or.i: src/Or.cpp.i

.PHONY : src/Or.i

# target to preprocess a source file
src/Or.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Or.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Or.cpp.i
.PHONY : src/Or.cpp.i

src/Or.s: src/Or.cpp.s

.PHONY : src/Or.s

# target to generate assembly for a file
src/Or.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Or.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Or.cpp.s
.PHONY : src/Or.cpp.s

src/Parser.o: src/Parser.cpp.o

.PHONY : src/Parser.o

# target to build an object file
src/Parser.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Parser.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Parser.cpp.o
.PHONY : src/Parser.cpp.o

src/Parser.i: src/Parser.cpp.i

.PHONY : src/Parser.i

# target to preprocess a source file
src/Parser.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Parser.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Parser.cpp.i
.PHONY : src/Parser.cpp.i

src/Parser.s: src/Parser.cpp.s

.PHONY : src/Parser.s

# target to generate assembly for a file
src/Parser.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Parser.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Parser.cpp.s
.PHONY : src/Parser.cpp.s

src/Semi.o: src/Semi.cpp.o

.PHONY : src/Semi.o

# target to build an object file
src/Semi.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Semi.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Semi.cpp.o
.PHONY : src/Semi.cpp.o

src/Semi.i: src/Semi.cpp.i

.PHONY : src/Semi.i

# target to preprocess a source file
src/Semi.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Semi.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Semi.cpp.i
.PHONY : src/Semi.cpp.i

src/Semi.s: src/Semi.cpp.s

.PHONY : src/Semi.s

# target to generate assembly for a file
src/Semi.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/Semi.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/Semi.cpp.s
.PHONY : src/Semi.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

unit_tests/test.o: unit_tests/test.cpp.o

.PHONY : unit_tests/test.o

# target to build an object file
unit_tests/test.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.o
.PHONY : unit_tests/test.cpp.o

unit_tests/test.i: unit_tests/test.cpp.i

.PHONY : unit_tests/test.i

# target to preprocess a source file
unit_tests/test.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.i
.PHONY : unit_tests/test.cpp.i

unit_tests/test.s: unit_tests/test.cpp.s

.PHONY : unit_tests/test.s

# target to generate assembly for a file
unit_tests/test.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.s
.PHONY : unit_tests/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... install/local"
	@echo "... list_install_components"
	@echo "... edit_cache"
	@echo "... rshell"
	@echo "... install/strip"
	@echo "... install"
	@echo "... gmock_main"
	@echo "... gmock"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... src/Add.o"
	@echo "... src/Add.i"
	@echo "... src/Add.s"
	@echo "... src/Command.o"
	@echo "... src/Command.i"
	@echo "... src/Command.s"
	@echo "... src/ConstructTree.o"
	@echo "... src/ConstructTree.i"
	@echo "... src/ConstructTree.s"
	@echo "... src/Or.o"
	@echo "... src/Or.i"
	@echo "... src/Or.s"
	@echo "... src/Parser.o"
	@echo "... src/Parser.i"
	@echo "... src/Parser.s"
	@echo "... src/Semi.o"
	@echo "... src/Semi.i"
	@echo "... src/Semi.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... unit_tests/test.o"
	@echo "... unit_tests/test.i"
	@echo "... unit_tests/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

