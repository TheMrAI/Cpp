cmake_minimum_required(VERSION 3.13.0)

add_executable(red_black_tree_tests red_black_tree_tests.cpp)

set_warning_levels(red_black_tree_tests)

target_link_libraries(red_black_tree_tests PUBLIC
    gtest_main
    red_black_tree
)

add_test(red_black_tree red_black_tree_tests)