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
CMAKE_SOURCE_DIR = /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam

# Include any dependencies generated for this target.
include CMakeFiles/stereo_particle_slam.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stereo_particle_slam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stereo_particle_slam.dir/flags.make

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o: CMakeFiles/stereo_particle_slam.dir/flags.make
CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o: /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam/src/stereo_image_processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o -c /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam/src/stereo_image_processor.cpp

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam/src/stereo_image_processor.cpp > CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.i

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam/src/stereo_image_processor.cpp -o CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.s

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.requires:

.PHONY : CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.requires

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.provides: CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.requires
	$(MAKE) -f CMakeFiles/stereo_particle_slam.dir/build.make CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.provides.build
.PHONY : CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.provides

CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.provides.build: CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o


# Object files for target stereo_particle_slam
stereo_particle_slam_OBJECTS = \
"CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o"

# External object files for target stereo_particle_slam
stereo_particle_slam_EXTERNAL_OBJECTS =

/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: CMakeFiles/stereo_particle_slam.dir/build.make
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libcv_bridge.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libimage_transport.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libmessage_filters.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libclass_loader.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/libPocoFoundation.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libdl.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libroscpp.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/librosconsole.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libroslib.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/librospack.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libeigen_conversions.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/liborocos-kdl.so.1.4.0
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/librostime.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /opt/ros/melodic/lib/libcpp_common.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so: CMakeFiles/stereo_particle_slam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stereo_particle_slam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stereo_particle_slam.dir/build: /home/teobaiguera/Documents/BeerDrone/devel/.private/stereo_particle_slam/lib/libstereo_particle_slam.so

.PHONY : CMakeFiles/stereo_particle_slam.dir/build

CMakeFiles/stereo_particle_slam.dir/requires: CMakeFiles/stereo_particle_slam.dir/src/stereo_image_processor.cpp.o.requires

.PHONY : CMakeFiles/stereo_particle_slam.dir/requires

CMakeFiles/stereo_particle_slam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stereo_particle_slam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stereo_particle_slam.dir/clean

CMakeFiles/stereo_particle_slam.dir/depend:
	cd /home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam /home/teobaiguera/Documents/BeerDrone/src/stereo_particle_slam /home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam /home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam /home/teobaiguera/Documents/BeerDrone/build/stereo_particle_slam/CMakeFiles/stereo_particle_slam.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stereo_particle_slam.dir/depend

