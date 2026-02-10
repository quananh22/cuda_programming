cmake_minimum_required(VERSION 3.22)
project (threads_practice LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Add debug symbols for debug builds
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add the executable
add_executable(threads_practice
    src/thread_example.cpp
)
