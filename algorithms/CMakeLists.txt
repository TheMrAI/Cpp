cmake_minimum_required(VERSION 3.13.0)

add_library(binary_search INTERFACE)
target_compile_features(binary_search INTERFACE cxx_std_17)
target_include_directories(binary_search INTERFACE include/)

add_library(heapsort INTERFACE)
target_compile_features(heapsort INTERFACE cxx_std_17)
target_include_directories(heapsort INTERFACE include/)

add_library(merge_sort INTERFACE)
target_compile_features(merge_sort INTERFACE cxx_std_17)
target_include_directories(merge_sort INTERFACE include/)

add_library(quicksort INTERFACE)
target_compile_features(quicksort INTERFACE cxx_std_17)
target_include_directories(quicksort INTERFACE include/)

add_library(counting_sort INTERFACE)
target_compile_features(counting_sort INTERFACE cxx_std_17)
target_include_directories(counting_sort INTERFACE include/)

add_library(radix_sort INTERFACE)
target_compile_features(radix_sort INTERFACE cxx_std_17)
target_include_directories(radix_sort INTERFACE include/)

add_library(maximal_subarray INTERFACE)
target_compile_features(maximal_subarray INTERFACE cxx_std_17)
target_include_directories(maximal_subarray INTERFACE include/)

add_library(dynamic_programming INTERFACE)
target_compile_features(dynamic_programming INTERFACE cxx_std_17)
target_include_directories(dynamic_programming INTERFACE include/)

add_subdirectory(tests)
add_subdirectory(benchmark)