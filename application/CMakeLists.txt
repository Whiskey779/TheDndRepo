cmake_minimum_required(VERSION 4.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TheDndRepo VERSION 1.0)
target_include_directories(TheDndRepo ${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB_RECURSE SRC_FILES src/*.cpp CONFIGURE_DEPENDS)
add_executable(TheDndRepo ${SRC_FILES})