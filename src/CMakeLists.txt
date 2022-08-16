# mkmp/src/


# set convenience definitions
set(SOURCE_DIR  ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# create lib from all sources but exclude main.cpp.
# Previously had a weird error where unit tests linked to main.cpp
file(GLOB SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX ".*main\\.cpp$")
add_library(mkmpLib ${SOURCES}) 
target_include_directories(mkmpLib PRIVATE ${INCLUDE_DIR})

