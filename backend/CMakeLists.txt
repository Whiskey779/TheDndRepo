cmake_minimum_required(VERSION 3.10)

# Project name and version
project(BackEnd VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add library (STATIC means static library)
file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(BackEnd STATIC ${SRC_FILES})

# Include directories for users of the library
target_include_directories(BackEnd PUBLIC ${PROJECT_SOURCE_DIR}/include)