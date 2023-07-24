find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(VecPointTests VecPointTests.cpp ../src/Point.cpp ../src/Vec.cpp)
target_link_libraries(VecPointTests GTest::gtest_main)
gtest_discover_tests(VecPointTests)

add_executable(ColorTests ColorTests.cpp ../src/Color.cpp)
target_link_libraries(ColorTests GTest::gtest_main)
gtest_discover_tests(ColorTests)
