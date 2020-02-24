cmake_minimum_required(VERSION 3.13.0)

project(Cpp_practice C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

add_subdirectory(object_orientation)
add_subdirectory(object_hierarchies)