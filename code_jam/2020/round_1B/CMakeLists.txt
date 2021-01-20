cmake_minimum_required(VERSION 3.13.0)

add_executable(expogo expogo.cpp)
target_compile_features(expogo PUBLIC
    cxx_std_17
)
set_warning_levels(expogo)
