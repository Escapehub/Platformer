cmake_minimum_required(VERSION 3.1)

project(Platformer) 

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(Platformer main.cpp)

target_link_libraries(Platformer sfml-graphics sfml-audio)

add_subdirectory(src/player)