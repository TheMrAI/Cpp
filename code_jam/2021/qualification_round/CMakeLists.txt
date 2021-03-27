cmake_minimum_required(VERSION 3.13.0)

add_executable(reversort reversort.cpp)
target_compile_features(reversort PUBLIC
    cxx_std_17
)
set_warning_levels(reversort)

add_executable(moons_and_umbrellas moons_and_umbrellas.cpp)
target_compile_features(moons_and_umbrellas PUBLIC
    cxx_std_17
)
set_warning_levels(moons_and_umbrellas)

add_executable(reversort_engineering reversort_engineering.cpp)
target_compile_features(reversort_engineering PUBLIC
    cxx_std_17
)
set_warning_levels(reversort_engineering)