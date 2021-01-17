cmake_minimum_required(VERSION 3.13.0)

project(Cpp_tinkering C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# release flags
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# debug flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -fsanitize=address")

function(set_warning_levels TARGET_NAME)
    if ( CMAKE_COMPILER_IS_GNUCC )
        target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra)
    endif()
    if ( MSVC )
        target_compile_options(${TARGET_NAME} PRIVATE /W4)
    endif()
endfunction()

add_subdirectory(../googletest ./build/) # googletest

enable_testing()

#Algorithms
add_subdirectory(algorithms)

# Containers
add_subdirectory(containers/linked_list)
add_subdirectory(containers/hash_map)
add_subdirectory(containers/red_black_tree)
add_subdirectory(containers/trie)

# cpp_lab
add_subdirectory(cpp_lab/noisy)
add_subdirectory(cpp_lab/object_orientation) # lab 1
add_subdirectory(cpp_lab/object_hierarchies) # lab 2
# lab 3
# lab 4
add_subdirectory(cpp_lab/lifetime_and_smart_pointers) # lab 5
add_subdirectory(cpp_lab/rvalue_references) # lab 6

# Code Jam
add_subdirectory(code_jam)