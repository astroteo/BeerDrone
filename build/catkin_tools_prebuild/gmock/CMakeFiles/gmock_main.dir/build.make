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
CMAKE_SOURCE_DIR = /usr/src/googletest/googlemock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock

# Include any dependencies generated for this target.
include CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gmock_main.dir/flags.make

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o: /usr/src/googletest/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o -c /usr/src/googletest/googletest/src/gtest-all.cc

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/googletest/googletest/src/gtest-all.cc > CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.i

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/googletest/googletest/src/gtest-all.cc -o CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.s

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.requires:

.PHONY : CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.requires

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.provides: CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.provides

CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.provides.build: CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o


CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: /usr/src/googletest/googlemock/src/gmock-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/gmock_main.dir/src/gmock-all.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.o -c /usr/src/googletest/googlemock/src/gmock-all.cc

CMakeFiles/gmock_main.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock-all.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/googletest/googlemock/src/gmock-all.cc > CMakeFiles/gmock_main.dir/src/gmock-all.cc.i

CMakeFiles/gmock_main.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock-all.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/googletest/googlemock/src/gmock-all.cc -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.s

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires:

.PHONY : CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o


CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: /usr/src/googletest/googlemock/src/gmock_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /usr/src/googletest/googlemock/src/gmock_main.cc

CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /usr/src/googletest/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /usr/src/googletest/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires:

.PHONY : CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o


# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

libgmock_main.a: CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/build.make
libgmock_main.a: CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libgmock_main.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gmock_main.dir/build: libgmock_main.a

.PHONY : CMakeFiles/gmock_main.dir/build

CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/usr/src/googletest/googletest/src/gtest-all.cc.o.requires
CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

.PHONY : CMakeFiles/gmock_main.dir/requires

CMakeFiles/gmock_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gmock_main.dir/clean

CMakeFiles/gmock_main.dir/depend:
	cd /home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /usr/src/googletest/googlemock /usr/src/googletest/googlemock /home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock /home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock /home/teobaiguera/Documents/BeerDrone/build/catkin_tools_prebuild/gmock/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gmock_main.dir/depend

