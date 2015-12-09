set(CPPTEST_SOURCE_DIR ${CMAKE_SOURCE_DIR}/cpptest_source/cpptest)
set(CPPTEST_BUILD_DIR  ${CMAKE_SOURCE_DIR}/cpptest_build)
set(CPPTEST_INC_DIR    ${CPPTEST_BUILD_DIR}/inc)
set(CPPTEST_LIB_DIR    ${CPPTEST_BUILD_DIR}/lib)
set(CPPTEST_LIB        cpptest)

find_library(CPPTEST
    NAMES ${CPPTEST_LIB}
    PATHS ${CPPTEST_BUILD_DIR}
)
include_directories(${CPPTEST_INC_DIR})
link_directories(${CPPTEST_LIB_DIR})

