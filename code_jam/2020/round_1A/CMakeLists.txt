cmake_minimum_required(VERSION 3.13.0)

add_executable(round_1A_pattern_matching round_1A_pattern_matching.cpp)
target_compile_features(round_1A_pattern_matching PUBLIC
    cxx_std_17
)
set_warning_levels(round_1A_pattern_matching)

add_executable(round_1A_pascal_walk round_1A_pascal_walk.cpp)
target_compile_features(round_1A_pascal_walk PUBLIC
    cxx_std_17
)
set_warning_levels(round_1A_pascal_walk)