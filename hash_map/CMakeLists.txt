cmake_minimum_required(VERSION 3.13.0)

add_library(hash_map INTERFACE)

target_compile_features(hash_map 
INTERFACE 
    cxx_std_17
)

target_include_directories(hash_map INTERFACE include/)

add_subdirectory(tests)