# package: find external packages
include(FindPkgConfig)

# package: add cpptest library
include(${CMAKE_SOURCE_DIR}/cpptest_build.cmake)

# compiler: include directories where the test source code is located
include_directories(${TEST_DIR})
include_directories(${TEST_DIR}/calls)
include_directories(${TEST_DIR}/rules)

# compiler: test source code files
set(TEST_SOURCES
    ${TEST_DIR}/calls/call_record_test.cpp
    ${TEST_DIR}/calls/call_time_test.cpp
    ${TEST_DIR}/rules/arithmetic_expression_test.cpp
    ${TEST_DIR}/rules/assignment_statement_test.cpp
    ${TEST_DIR}/rules/rule_line_test.cpp
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
)

# cmake: install
install(TARGETS ${TEST} DESTINATION ${PROJECT_SOURCE_DIR})
