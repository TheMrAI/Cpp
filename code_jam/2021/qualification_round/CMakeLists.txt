cmake_minimum_required(VERSION 3.13.0)

add_executable(reversort reversort.cpp)
target_compile_features(reversort PUBLIC
    cxx_std_17
)
set_warning_levels(reversort)