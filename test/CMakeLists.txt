cmake_minimum_required(VERSION 3.14)
project(ShoppingListTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

# File sorgente del progetto principale (usa la radice del progetto)
set(PROJECT_SOURCES
        ${CMAKE_SOURCE_DIR}/item.cpp
        ${CMAKE_SOURCE_DIR}/category.cpp
        ${CMAKE_SOURCE_DIR}/shoppingList.cpp
        ${CMAKE_SOURCE_DIR}/user.cpp
        ${CMAKE_SOURCE_DIR}/userManager.cpp
)

# File di test
set(TEST_SOURCE_FILES
        runAllTests.cpp
        itemTest.cpp
        shoppingListTest.cpp
        userTest.cpp
        userManagerTest.cpp
        categoryTest.cpp
)

# Crea l'eseguibile includendo sia i test che i sorgenti del progetto
add_executable(runAllTests ${TEST_SOURCE_FILES} ${PROJECT_SOURCES})

target_link_libraries(runAllTests gtest gtest_main)