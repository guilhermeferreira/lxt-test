# package: find external packages
include(FindPkgConfig)

# compiler: creates the binary
add_executable(${TARGET}
    ${TARGET_SOURCES}
    ${TARGET_DIR}/main.cpp
)

# cmake: install
install(TARGETS ${TARGET} DESTINATION ${PROJECT_SOURCE_DIR})
