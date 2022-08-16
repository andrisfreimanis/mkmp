# mkmp/test/ut_PointManager/

# set convenience definitions
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(ut_PointManager ut_PointManager.cpp)
target_link_libraries(ut_PointManager PRIVATE mkmpLib)
target_include_directories(ut_PointManager PRIVATE ${INCLUDE_DIR})

add_test(ut_PointManager ./ut_PointManager)


# add links to the required csv files
set(LN_DEST_DIR ${CMAKE_BINARY_DIR}/test/ut_PointManager)
file(GLOB TEST_FILES "*.csv")
foreach(FILE ${TEST_FILES})
  get_filename_component(FILENAME ${FILE} NAME) 
  execute_process(COMMAND rm ${LN_DEST_DIR}/${FILENAME})
  execute_process(COMMAND cp ${FILE} ${LN_DEST_DIR}/${FILENAME})
endforeach()
