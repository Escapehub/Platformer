cmake_minimum_required(VERSION 3.16)

project(Platformer)

set(
    SOURCES
    main.cpp
    src/player/player.cpp
    src/enemy/enemy.cpp
    src/enemyhelper/enemyhelper.cpp
    src/levelgen/levelgen.cpp
)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")
INCLUDE_DIRECTORIES("${BASEPATH}/player")
INCLUDE_DIRECTORIES("${BASEPATH}/levelgen")
    
add_executable(Platformer ${SOURCES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

set_property(TARGET Platformer PROPERTY CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Platformer sfml-graphics sfml-audio)
