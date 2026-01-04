file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(backend STATIC ${SRC_FILES})
target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
