cmake_minimum_required(VERSION 3.13.0)

find_package(benchmark REQUIRED)

add_executable(binary_search_bench binary_search.cpp)
target_link_libraries(binary_search_bench PUBLIC
    benchmark::benchmark
    binary_search
)
set_warning_levels(binary_search_bench)

add_executable(comparison_sorts_bench comparison_sorts.cpp)
target_link_libraries(comparison_sorts_bench PUBLIC
    benchmark::benchmark
    heapsort
    merge_sort
    quicksort
)
set_warning_levels(comparison_sorts_bench)

add_executable(non_comparison_sorts_bench non_comparison_sorts.cpp)
target_link_libraries(non_comparison_sorts_bench PUBLIC
    benchmark::benchmark
    counting_sort
    radix_sort
)
set_warning_levels(non_comparison_sorts_bench)