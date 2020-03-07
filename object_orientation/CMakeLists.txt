cmake_minimum_required(VERSION 3.13.0)

add_executable(Draw_with_C draw_function_c.c)
set_target_properties(Draw_with_C PROPERTIES LINKER_LANGUAGE C)
target_link_libraries(Draw_with_C m)

add_executable(Draw_with_Cpp draw_function_cpp.cpp)
if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(Draw_with_Cpp PRIVATE -Wall -Wextra)
endif()
if ( MSVC )
    target_compile_options(Draw_with_Cpp PRIVATE /W4)
endif()