cmake_minimum_required(VERSION 3.13.0)

add_executable(binary_search_tests binary_search_tests.cpp)

target_link_libraries(binary_search_tests PUBLIC
    gtest_main
    binary_search
)