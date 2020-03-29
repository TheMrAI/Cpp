cmake_minimum_required(VERSION 3.13.0)

project(Cpp_practice C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

function(set_warning_levels TARGET_NAME)
    if ( CMAKE_COMPILER_IS_GNUCC )
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)
    endif()
    if ( MSVC )
        target_compile_options(${TARGET_NAME} PRIVATE /W4)
    endif()
endfunction()

add_subdirectory(../googletest ./build/) # googletest

add_subdirectory(noisy)

add_subdirectory(object_orientation) # lab 1
add_subdirectory(object_hierarchies) # lab 2
# lab 3
# lab 4
add_subdirectory(lifetime_and_smart_pointers) # lab 5
add_subdirectory(rvalue_references) # lab 6

# Containers
add_subdirectory(linked_list)
add_subdirectory(hash_map)

#Algorithms
add_subdirectory(algorithms)