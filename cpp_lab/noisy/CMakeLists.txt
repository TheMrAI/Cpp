cmake_minimum_required(VERSION 3.13.0)

add_library(noisy STATIC
    src/Noisy.cpp)
target_include_directories(noisy PUBLIC include)
set_warning_levels(noisy)