add_executable(test_future test_future.cpp)
target_link_libraries(test_future gtest_main future)
include(GoogleTest)
gtest_discover_tests(test_future)
