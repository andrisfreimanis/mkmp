cmake_minimum_required(VERSION 3.10)

# set the project name
project(mkmp 
        VERSION 0.1
        LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(test)

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


# check where to put the executable
if (NOT CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_INSTALL_PREFIX}/bin)
else ()
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
message("Will put the executable in: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/bin.")


# set convenience definitions
set(BIN_DIR     ${CMAKE_SOURCE_DIR}/bin)
set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR    ${CMAKE_SOURCE_DIR}/test)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
include_directories(
  ${SOURCE_DIR}
  ${INCLUDE_DIR}
  ${TEST_DIR}
)


file(GLOB HEADERS "${INCLUDE_DIR}/*.hpp")
file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

# executable
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

message("")