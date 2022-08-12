cmake_minimum_required(VERSION 3.10)

# set the project name
project(MKMP VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

message("")

## compiler flags
set(CMAKE_CXX_FLAGS "-std=c++20 -Wall -Werror -Wextra")
if (${CMAKE_BUILD_TYPE} MATCHES "DEBUG")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o0 -g")
elseif (${CMAKE_BUILD_TYPE} MATCHES "RELEASE")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o3")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o2")
endif()

message("Will build with: ${CMAKE_CXX_FLAGS}")


# set convenience definitions
set(BIN_DIR     ${CMAKE_SOURCE_DIR}/bin)
set(SRC_DIR     ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR    ${CMAKE_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Glob files
file(GLOB SOURCES "${SRC_DIR}/*.cpp")

# check where to put the executable
if (CMAKE_INSTALL_PREFIX)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin)
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endif()
message("Will put the executable in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bin.")


# add the executable
add_executable(mkmp ${SOURCES})


message("")