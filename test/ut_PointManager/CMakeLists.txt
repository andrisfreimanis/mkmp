# mkmp/test/ut_PointManager/

# set convenience definitions
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(ut_PointManager ut_PointManager.cpp)
target_link_libraries(ut_PointManager PRIVATE mkmpLib)
target_include_directories(ut_PointManager PRIVATE ${INCLUDE_DIR})

add_test(ut_PointManager ./ut_PointManager)