cmake_minimum_required(VERSION 3.0)

project(demo)

set(SRC_LIST main.cpp)

add_library(mylib STATIC point.cpp circle.cpp)

add_executable(demo ${SRC_LIST})

target_link_libraries(demo mylib)