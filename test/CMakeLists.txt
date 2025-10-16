cmake_minimum_required(VERSION 3.14)
project(ShoppingListTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
set(TEST_SOURCE_FILES runAllTests.cpp itemTest.cpp shoppingListTest.cpp userTest.cpp)
add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main)