# mkmp/test/ut_PointManager/

# set convenience definitions
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(ut_PointManager ut_PointManager.cpp)
target_link_libraries(ut_PointManager PRIVATE mkmpLib)
target_include_directories(ut_PointManager PRIVATE ${INCLUDE_DIR})

add_test(ut_PointManager ./ut_PointManager)

# add links to necessary csv files
set(LN_SOURCE_DIR ${CMAKE_SOURCE_DIR}/test/ut_PointManager)
set(LN_DEST_DIR ${CMAKE_BINARY_DIR}/test/ut_PointManager)
execute_process(COMMAND ln -sf ${LN_SOURCE_DIR}/emptyFile.csv ${LN_DEST_DIR}/emptyFile.csv)
execute_process(COMMAND ln -sf ${LN_SOURCE_DIR}/1D.csv ${LN_DEST_DIR}/1D.csv)
execute_process(COMMAND ln -sf ${LN_SOURCE_DIR}/2D.csv ${LN_DEST_DIR}/2D.csv)
