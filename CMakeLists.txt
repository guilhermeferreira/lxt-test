# cmake: build options
set(CMAKE_COLOR_MAKEFILE ON)
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# compiler: add definitions and arguments to the compiler
add_definitions(
    -Wall
    -Wextra
    -Weffc++
    -Wshadow
    -Wabi
    -Winline
    -Wmissing-declarations
    -Wmissing-format-attribute
    -Woverloaded-virtual
    -Wpacked
    -Wredundant-decls
    -Wsign-promo
    -Wstack-protector -fstack-protector
    -Wswitch-default
    -Wfloat-equal
    -Wcast-qual
    -Wconversion
)

# cmake: build the each application in their source directory
add_subdirectory(problem_1)
add_subdirectory(problem_2)
add_subdirectory(problem_3)
add_subdirectory(problem_4)

include(CPack)
