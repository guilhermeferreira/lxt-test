# package: find external packages
include(FindPkgConfig)

# package: add cpptest library
include(${CMAKE_SOURCE_DIR}/cpptest_build.cmake)

# compiler: add coverage definitions to the compiler
add_definitions(
    -O0
    -fprofile-arcs
    -ftest-coverage
)

# compiler: creates the binaries
add_executable(${TEST}
    ${TARGET_SOURCES}
    ${TEST_DIR}/rotation_test.cpp
    ${TEST_DIR}/main.cpp
)

# linker: link the program against the libraries
target_link_libraries(${TEST}
    ${CPPTEST_LIB}
    -lgcov
)

# cmake: install
install(TARGETS ${TEST} DESTINATION ${PROJECT_SOURCE_DIR})
