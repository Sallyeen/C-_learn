cmake_minimum_required(VERSION 3.0)

project(task2)

set(SRC_LIST main.cpp)

add_library(mylib STATIC ope.cpp)

add_executable(task2 ${SRC_LIST})

target_link_libraries(task2 mylib)