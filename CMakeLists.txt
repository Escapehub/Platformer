cmake_minimum_required(VERSION 3.16)

project(Platformer)

set(
    SOURCES
    main.cpp
    src/player/player.cpp
)
    
add_executable(Platformer ${SOURCES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Platformer sfml-graphics sfml-audio)
