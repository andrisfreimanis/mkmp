# mkmp/src/


# set convenience definitions
set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "*.cpp")

add_library(mkmpLib ${SOURCES}) 
target_include_directories(mkmpLib PRIVATE ${INCLUDE_DIR})

