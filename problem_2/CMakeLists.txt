# project: definitions
project(problem_2)
set(VERSION 0.1)
set(VERSION_REVISION 1)
set(TARGET ${PROJECT_NAME})
set(TARGET_DIR ${PROJECT_SOURCE_DIR})

# package: find external packages
include(FindPkgConfig)

# compiler: include directories where the target source code is located
include_directories(${TARGET_DIR})

# compiler: source code files
set(SOURCES
    main.cpp
)

# compiler: creates the binary
add_executable(${TARGET} ${SOURCES})

# cmake: install
install(TARGETS ${TARGET} DESTINATION ${PROJECT_SOURCE_DIR})

include(CPack)
