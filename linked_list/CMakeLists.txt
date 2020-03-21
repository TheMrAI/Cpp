cmake_minimum_required(VERSION 3.13.0)

add_library(linked_list
STATIC
    src/linked_list.cpp
)

target_compile_features(linked_list 
PUBLIC 
    cxx_std_17
)

target_include_directories(linked_list
PUBLIC
    include
)

target_sources(linked_list
PUBLIC
    src
)

set_warning_levels(linked_list)

add_subdirectory(tests)