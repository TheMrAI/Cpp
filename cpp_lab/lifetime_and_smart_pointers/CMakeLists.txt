cmake_minimum_required(VERSION 3.13.0)

add_executable(herons_formula
    herons_formula.cpp
)
target_compile_features(herons_formula
PRIVATE
    cxx_std_17
)
set_warning_levels(herons_formula)

add_executable(numerical_derivative
    numerical_derivative.cpp
)
target_compile_features(numerical_derivative
PRIVATE
     cxx_std_17
)
set_warning_levels(numerical_derivative)