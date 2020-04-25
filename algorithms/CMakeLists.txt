cmake_minimum_required(VERSION 3.13.0)

add_library(binary_search INTERFACE)
target_compile_features(binary_search INTERFACE cxx_std_17)
target_include_directories(binary_search INTERFACE include/)

add_library(merge_sort INTERFACE)
target_compile_features(merge_sort INTERFACE cxx_std_17)
target_include_directories(merge_sort INTERFACE include/)

add_library(quick_sort INTERFACE)
target_compile_features(quick_sort INTERFACE cxx_std_17)
target_include_directories(quick_sort INTERFACE include/)

add_subdirectory(tests)