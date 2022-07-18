cmake_minimum_required(VERSION 3.0)

project(task4)

set(CMAKE_BUILD_TYPE DEBUG)

set(SRC_LIST main.cpp)

add_library(mylib STATIC room_base.cpp room.cpp role.cpp role_base.cpp)

add_executable(task4 ${SRC_LIST})

target_link_libraries(task4 mylib)