cmake_minimum_required(VERSION 3.10)
project(autocomplete)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add the src directory to the build
add_subdirectory(src)

# Add the lib directory to the build
add_subdirectory(lib)

# Add include paths
include_directories(/usr/include)