cmake_minimum_required(VERSION 3.10)

# set the project name
project(MKMP VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set convenience definitions
set(BIN_DIR     ${CMAKE_SOURCE_DIR}/bin)
set(SRC_DIR     ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR    ${CMAKE_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# add source dir
#include_directories(
#${BIN_DIR}
#${SRC_DIR}
#${TEST_DIR}
#${INCLUDE_DIR}
#)

# Glob files
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# put executable in /bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# add the executable
add_executable(mkmp ${SOURCES})


