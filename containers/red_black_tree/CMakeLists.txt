cmake_minimum_required(VERSION 3.13.0)

add_library(red_black_tree INTERFACE)

target_compile_features(red_black_tree 
INTERFACE 
    cxx_std_17
)

target_include_directories(red_black_tree INTERFACE include/)

add_subdirectory(tests)