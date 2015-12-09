# project: definitions
project(problem_4)
set(VERSION 0.1)
set(VERSION_REVISION 1)
set(TARGET ${PROJECT_NAME})
set(TEST   ${PROJECT_NAME}_test)
set(TARGET_DIR ${PROJECT_SOURCE_DIR}/src)
set(TEST_DIR   ${PROJECT_SOURCE_DIR}/test)

# compiler: include directories where the target source code is located
include_directories(${TARGET_DIR})
include_directories(${TARGET_DIR}/calls)
include_directories(${TARGET_DIR}/excp)
include_directories(${TARGET_DIR}/rules)

# compiler: source code files
set(TARGET_SOURCES
    ${TARGET_DIR}/calls/calls_file.cpp
    ${TARGET_DIR}/calls/call_record.cpp
    ${TARGET_DIR}/calls/calls.cpp
    ${TARGET_DIR}/calls/call_time.cpp
    ${TARGET_DIR}/rules/division_operation.cpp
    ${TARGET_DIR}/rules/object.cpp
    ${TARGET_DIR}/rules/condition_expression.cpp
    ${TARGET_DIR}/rules/rules_file.cpp
    ${TARGET_DIR}/rules/arithmetic_expression.cpp
    ${TARGET_DIR}/rules/statement.cpp
    ${TARGET_DIR}/rules/command_statement.cpp
    ${TARGET_DIR}/rules/assignment_statement.cpp
    ${TARGET_DIR}/rules/rule_line.cpp
    ${TARGET_DIR}/rules/token.cpp
    ${TARGET_DIR}/rules/rules.cpp
    ${TARGET_DIR}/rules/subtraction_operation.cpp
    ${TARGET_DIR}/rules/multiplication_operation.cpp
    ${TARGET_DIR}/rules/expression.cpp
    ${TARGET_DIR}/rules/addition_operation.cpp
    ${TARGET_DIR}/rules/object_table.cpp
    ${TARGET_DIR}/rules/selection_statement.cpp
    ${TARGET_DIR}/rules/operation.cpp
    ${TARGET_DIR}/rules/statement_factory.cpp
    ${TARGET_DIR}/rules/operation_table.cpp
)

# cmake: build the application in the source directory
add_subdirectory(src)

# cmake: build the test cases
add_subdirectory(test)

include(CPack)
