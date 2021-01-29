cmake_minimum_required(VERSION 3.13.0)

add_executable(modification_order src/modification_order.cpp)
target_include_directories(modification_order PUBLIC
    include/
)
set_warning_levels(modification_order)
