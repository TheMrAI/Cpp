cmake_minimum_required(VERSION 3.13.0)

add_executable(hash_map_unit_tests hash_map_unit_tests.cpp)

set_warning_levels(hash_map_unit_tests)

target_link_libraries(hash_map_unit_tests PUBLIC
    gtest_main
    hash_map
)

add_test(hash_map hash_map_unit_tests)