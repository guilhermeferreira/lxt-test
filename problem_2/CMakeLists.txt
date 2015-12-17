# project: definitions
project(problem_2)
set(VERSION 0.1)
set(VERSION_REVISION 1)
set(TARGET ${PROJECT_NAME})
set(TEST   ${PROJECT_NAME}_test)
set(TARGET_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR   ${PROJECT_SOURCE_DIR}/test)

# compiler: include directories where the target source code is located
include_directories(${TARGET_DIR})
include_directories(${TEST_DIR})

# compiler: source code files
set(TARGET_SOURCES
    ${TARGET_DIR}/missing_letters.cpp
)

# cmake: build the application in the source directory
add_subdirectory(src)

# cmake: build the test cases
add_subdirectory(test)

include(CPack)
