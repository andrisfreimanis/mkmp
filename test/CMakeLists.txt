set(TARGET test)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)


add_executable(ut_PointManager ut_PointManager.cpp)
target_include_directories(ut_PointManager PRIVATE ${INCLUDE_DIR})
target_link_libraries(ut_PointManager ${SOURCE_DIR})

add_test(ut_PointManager ./ut_PoutPeridigm_MultiphysicsElasticMaterial)