cmake_minimum_required(VERSION 3.13.0)

add_library(linked_list INTERFACE)

target_compile_features(linked_list 
INTERFACE 
    cxx_std_17
)

target_include_directories(linked_list INTERFACE include/)

#set_warning_levels(linked_list)

add_subdirectory(tests)