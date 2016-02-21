# package: find external packages
include(FindPkgConfig)

# package: add cpptest library
include(${CMAKE_SOURCE_DIR}/cpptest_build.cmake)

# compiler: include directories where the test source code is located
include_directories(${TEST_DIR})

# compiler: add coverage definitions to the compiler
add_definitions(
    -O0
    -fprofile-arcs
    -ftest-coverage
)

# compiler: test source code files
set(TEST_SOURCES
    ${TEST_DIR}/linearchamber_test.cpp
    ${TEST_DIR}/particle_test.cpp
)

# compiler: creates the binaries
add_executable(${TEST}
    ${TARGET_SOURCES}
    ${TEST_SOURCES}
    ${TEST_DIR}/main.cpp
)

# linker: link the program against the libraries
target_link_libraries(${TEST}
    ${CPPTEST_LIB}
    -lgcov
)

# cmake: install
install(TARGETS ${TEST} DESTINATION ${PROJECT_SOURCE_DIR})
