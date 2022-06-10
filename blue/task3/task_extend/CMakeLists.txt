cmake_minimum_required(VERSION 3.0)

project(task3)

# set(SRC_LIST encrypt.cpp)

add_library(mylib STATIC ope_extend.cpp)

add_executable(entask encrypt_extend.cpp)

add_executable(detask decrypt_extend.cpp)

target_link_libraries(entask mylib)

target_link_libraries(detask mylib)