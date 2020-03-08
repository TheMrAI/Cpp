cmake_minimum_required(VERSION 3.13.0)

add_executable(linked_list_tests linked_list_tests.cpp)

target_link_libraries(linked_list_tests PUBLIC
    gtest_main
    linked_list
)