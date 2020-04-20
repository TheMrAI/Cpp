cmake_minimum_required(VERSION 3.13.0)

add_executable(binary_search_tests binary_search_tests.cpp)
target_link_libraries(binary_search_tests PUBLIC
    gtest_main
    binary_search
)
add_test(binary_search binary_search_tests)

add_executable(merge_sort_tests merge_sort_tests.cpp)
target_link_libraries(merge_sort_tests PUBLIC
    gtest_main
    merge_sort
)
add_test(merge_sort merge_sort_tests)