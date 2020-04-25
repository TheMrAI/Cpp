cmake_minimum_required(VERSION 3.13.0)

add_executable(binary_search_tests binary_search_tests.cpp)
target_link_libraries(binary_search_tests PUBLIC
    gtest_main
    binary_search
)
set_warning_levels(binary_search_tests)
add_test(binary_search binary_search_tests)

add_executable(merge_sort_tests merge_sort_tests.cpp)
target_link_libraries(merge_sort_tests PUBLIC
    gtest_main
    merge_sort
)
set_warning_levels(merge_sort_tests)
add_test(merge_sort merge_sort_tests)

add_executable(quick_sort_tests quick_sort_tests.cpp)
target_link_libraries(quick_sort_tests PUBLIC
    gtest_main
    quick_sort
)
set_warning_levels(quick_sort_tests)
add_test(quick_sort quick_sort_tests)