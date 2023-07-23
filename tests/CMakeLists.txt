find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(TupleTests TupleTests.cpp ../src/Point.cpp ../src/Vec.cpp)
target_link_libraries(TupleTests GTest::gtest_main)

gtest_discover_tests(TupleTests)
