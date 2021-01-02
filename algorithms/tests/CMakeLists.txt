cmake_minimum_required(VERSION 3.13.0)

add_executable(binary_search_tests binary_search_tests.cpp)
target_link_libraries(binary_search_tests PUBLIC
    gtest_main
    binary_search
)
set_warning_levels(binary_search_tests)
add_test(binary_search binary_search_tests)

add_executable(heapsort_tests heapsort_tests.cpp)
target_link_libraries(heapsort_tests PUBLIC
    gtest_main
    heapsort
)
set_warning_levels(heapsort_tests)
add_test(heapsort heapsort_tests)

add_executable(merge_sort_tests merge_sort_tests.cpp)
target_link_libraries(merge_sort_tests PUBLIC
    gtest_main
    merge_sort
)
set_warning_levels(merge_sort_tests)
add_test(merge_sort merge_sort_tests)

add_executable(quicksort_tests quicksort_tests.cpp)
target_link_libraries(quicksort_tests PUBLIC
    gtest_main
    quicksort
)
set_warning_levels(quicksort_tests)
add_test(quicksort quicksort_tests)

add_executable(counting_sort_tests counting_sort_tests.cpp)
target_link_libraries(counting_sort_tests PUBLIC
    gtest_main
    counting_sort
)
set_warning_levels(counting_sort_tests)
add_test(counting_sort counting_sort_tests)

add_executable(maximal_subarray_tests maximal_subarray_tests.cpp)
target_link_libraries(maximal_subarray_tests PUBLIC
    gtest_main
    maximal_subarray
)
set_warning_levels(maximal_subarray_tests)
add_test(maximal_subarray maximal_subarray_tests)

add_executable(dynamic_programming_tests dynamic_programming_tests.cpp)
target_link_libraries(dynamic_programming_tests PUBLIC
    gtest_main
    dynamic_programming
)
set_warning_levels(dynamic_programming_tests)
add_test(dynamic_programming dynamic_programming_tests)