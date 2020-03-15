cmake_minimum_required(VERSION 3.13.0)


add_executable(optimize_copy optimize_copy.cpp)
target_link_libraries(optimize_copy
PRIVATE
    noisy)
set_warning_levels(optimize_copy)

# see the same code with copy ellision disabled
add_executable(optimize_copy_no_copy_ellision optimize_copy.cpp)
target_compile_options(optimize_copy_no_copy_ellision
PRIVATE
    -fno-elide-constructors)
target_link_libraries(optimize_copy_no_copy_ellision
PRIVATE
    noisy)
set_warning_levels(optimize_copy_no_copy_ellision)