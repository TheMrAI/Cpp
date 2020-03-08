cmake_minimum_required(VERSION 3.13.0)

add_executable(herons_formula herons_formula.cpp)
target_compile_features(herons_formula PRIVATE cxx_std_17)
set_warning_level(herons_formula)
