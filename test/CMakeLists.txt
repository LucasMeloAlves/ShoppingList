add_subdirectory(lib/googletest)
include_directories(lib/googletest/include)


set(TEST_SOURCE_FILES runAllTests.cpp ItemTest.cpp ListTest.cpp UserTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main)