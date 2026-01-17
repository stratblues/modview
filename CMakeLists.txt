cmake_minimum_required(VERSION 3.16)
project(modview)

# 1. Point directly to your SDL source folder
# This builds SDL3 alongside your project and avoids "IMPORTED_LOCATION" bugs
add_subdirectory(${CMAKE_HOME_DIRECTORY}/../SDL ${CMAKE_BINARY_DIR}/SDL_build)

add_executable(ModView main.cpp)

# 2. Link against the guaranteed target name
target_link_libraries(ModView PRIVATE SDL3::SDL3)
