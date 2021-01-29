cmake_minimum_required(VERSION 3.13.0)

find_package(benchmark REQUIRED)

add_executable(modification_orders_bench modification_orders.cpp)
target_link_libraries(modification_orders_bench PUBLIC
    benchmark::benchmark
)
target_include_directories(modification_orders_bench PUBLIC
    ../include/
)
set_warning_levels(modification_orders_bench)