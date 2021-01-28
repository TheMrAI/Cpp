cmake_minimum_required(VERSION 3.13.0)

add_executable(overexcited_fan overexcited_fan.cpp)
target_compile_features(overexcited_fan PUBLIC
    cxx_std_17
)
set_warning_levels(overexcited_fan)

add_executable(overrandomized overrandomized.cpp)
target_compile_features(overrandomized PUBLIC
    cxx_std_17
)
set_warning_levels(overrandomized)
