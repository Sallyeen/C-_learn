cmake_minimum_required(VERSION 3.0)
project(GAME)

include_directories("./RoomRole")
add_library(mylib STATIC 
            ./RoomRole/dungeon.cpp ./RoomRole/role.cpp 
            ./RoomRole/rooms_all.cpp ./RoomRole/parts_all.cpp)

add_executable(project_4 game_impl.cpp)

target_link_libraries(project_4 mylib)