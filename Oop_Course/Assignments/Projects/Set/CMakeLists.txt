cmake_minimum_required(VERSION 3.19.6)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(set)
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(app ${SRC_FILES})