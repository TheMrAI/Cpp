cmake_minimum_required(VERSION 3.13.0)

add_executable(expogo expogo.cpp)
target_compile_features(expogo PUBLIC
    cxx_std_17
)
set_warning_levels(expogo)

add_executable(blindfolded_bullseye blindfolded_bullseye.cpp)
target_compile_features(blindfolded_bullseye PUBLIC
    cxx_std_17
)
set_warning_levels(blindfolded_bullseye)