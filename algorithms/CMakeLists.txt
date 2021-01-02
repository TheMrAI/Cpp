cmake_minimum_required(VERSION 3.13.0)

add_library(algorithms INTERFACE)
target_compile_features(algorithms INTERFACE cxx_std_17)
target_include_directories(algorithms INTERFACE include/)

add_subdirectory(tests)
add_subdirectory(benchmark)