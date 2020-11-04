cmake_minimum_required(VERSION 3.13.0)

find_package(benchmark REQUIRED)

add_executable(binary_search_bench binary_search.cpp)
target_link_libraries(binary_search_bench PUBLIC
    benchmark::benchmark
    binary_search
)
set_warning_levels(binary_search_bench)