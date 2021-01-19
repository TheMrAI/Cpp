cmake_minimum_required(VERSION 3.13.0)

add_executable(pattern_matching pattern_matching.cpp)
target_compile_features(pattern_matching PUBLIC
    cxx_std_17
)
set_warning_levels(pattern_matching)

add_executable(pascal_walk pascal_walk.cpp)
target_compile_features(pascal_walk PUBLIC
    cxx_std_17
)
set_warning_levels(pascal_walk)

add_executable(square_dance square_dance.cpp)
target_compile_features(square_dance PUBLIC
    cxx_std_17
)
set_warning_levels(square_dance)