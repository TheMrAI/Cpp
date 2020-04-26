cmake_minimum_required(VERSION 3.13.0)

add_executable(trie_tests trie_tests.cpp)

set_warning_levels(trie_tests)

target_link_libraries(trie_tests PUBLIC
    gtest_main
    trie
)

add_test(trie trie_tests)