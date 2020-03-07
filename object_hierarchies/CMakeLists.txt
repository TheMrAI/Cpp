cmake_minimum_required(VERSION 3.13.0)

add_executable(sieve_of_eratosthenes sieve_of_eratosthenes.cpp)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(sieve_of_eratosthenes PRIVATE -Wall -Wextra)
endif()
if ( MSVC )
    target_compile_options( PRIVATE /W4)
endif()

add_executable(reverse_polish_notation reverse_polish_notation.cpp)
target_compile_features(reverse_polish_notation PRIVATE cxx_std_17)