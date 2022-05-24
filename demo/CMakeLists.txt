cmake_minimum_required(VERSION 3.0)
project(SUM)

set (CMAKE_BUILD_TYPE,Debug)

add_library(mylib STATIC sum_io.cpp sum_process.cpp)

add_executable(project_2 sum_impl.cpp)

target_link_libraries(project_2 mylib)