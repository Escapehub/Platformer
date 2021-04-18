cmake_minimum_required(VERSION 3.16)

project(Platformer VERSION 1.0.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug 
    CACHE STRING 
      "Choose the type of build (Debug or Release)" FORCE)
endif()

# Export compile commands for completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set option to control setting the resource path variable
option(USE_INSTALL_RESOURCE_PATH "Set resource path to install location" OFF)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Link sfml statically 
set(SFML_STATIC_LIBRARIES TRUE)

# Fin SFML shared libraries
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

file(
	GLOB
  SOURCES
  "include/*.h"
  "src/*.cxx"
)
# Compile executable
add_executable(Platformer ${SOURCES})

# Set include directory search paths
target_include_directories(Platformer 
  PRIVATE
    "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/"
)

# Set executable RPATH
set_target_properties(Platformer
  PROPERTIES
      INSTALL_RPATH
        "${CMAKE_INSTALL_PREFIX}/lib"
)

# Link executable to required SFML modules
target_link_libraries(Platformer sfml-graphics sfml-audio)

# Set executable install location
install(TARGETS Platformer DESTINATION bin)

# Set install location for resources
install(DIRECTORY content
  DESTINATION "${CMAKE_INSTALL_PREFIX}/share/${CMAKE_PROJECT_NAME}"
)