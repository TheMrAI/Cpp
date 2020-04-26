cmake_minimum_required(VERSION 3.13.0)

add_library(trie STATIC src/trie.cpp)

target_compile_features(trie 
PUBLIC 
    cxx_std_17
)

target_include_directories(trie PUBLIC include/)
set_warning_levels(trie)

add_subdirectory(tests)