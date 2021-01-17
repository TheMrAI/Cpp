cmake_minimum_required(VERSION 3.13.0)

add_executable(round_1A round_1A.cpp)
target_compile_features(round_1A PUBLIC
    cxx_std_17
)
set_warning_levels(round_1A)