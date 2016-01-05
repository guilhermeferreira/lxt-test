# package: find external packages
include(FindPkgConfig)

# package: add cpptest library
include(${CMAKE_SOURCE_DIR}/cpptest_build.cmake)

# compiler: creates the binaries
add_executable(${TEST}
    ${TARGET_SOURCES}
    ${TEST_DIR}/missing_letters_test.cpp
    ${TEST_DIR}/main.cpp
)

# linker: link the program against the libraries
target_link_libraries(${TEST}
    ${CPPTEST_LIB}
)

# cmake: install
install(TARGETS ${TEST} DESTINATION ${PROJECT_SOURCE_DIR})
