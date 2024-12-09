add_executable(tests test-day1.cpp)
target_link_libraries(tests advent_2024_library gtest gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(tests WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})