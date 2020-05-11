add_executable(all_tests test_main.cpp)
find_package(doctest CONFIG REQUIRED)
target_link_libraries(all_tests PRIVATE template doctest::doctest)
add_test(NAME all_tests COMMAND all_tests)
