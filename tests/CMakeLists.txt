find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(TupleVecPointTests TupleVecPointTests.cpp ../src/Point.cpp
                                  ../src/Vec.cpp)
target_link_libraries(TupleVecPointTests GTest::gtest_main)
gtest_discover_tests(TupleVecPointTests)

add_executable(ColorTests ColorTests.cpp ../src/Color.cpp)
target_link_libraries(ColorTests GTest::gtest_main Qt6::Gui)
gtest_discover_tests(ColorTests)

add_executable(MatrixTests MatrixTests.cpp ../src/Point.cpp ../src/Vec.cpp)
target_link_libraries(MatrixTests GTest::gtest_main)
gtest_discover_tests(MatrixTests)
