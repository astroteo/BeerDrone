cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(test_extract_orb_feat CXX C)

# Libraries
find_package( OpenCV REQUIRED )

# Include and src
################################################################################
include_directories("include")
add_library(project_lib src/orbExtractor.cpp src/matcherTriangulator.cpp)

################################################################################
# Executable
add_executable(main main.cpp)

target_link_libraries(project_lib ${OpenCV_LIBS})
target_link_libraries(main PUBLIC project_lib)


# Add flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")
