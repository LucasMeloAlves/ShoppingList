cmake_minimum_required(VERSION 4.0)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)
set(SOURCE_FILES Item.cpp Item.h ShoppingList.cpp ShoppingList.h User.cpp User.h UserManager.cpp UserManager.h Observer.h Subject.h Category.cpp Category.h main.cpp)
add_executable(ShoppingList ${SOURCE_FILES})
add_library(core ${SOURCE_FILES}
        main.cpp
        test/categoryTest.cpp)
target_link_libraries(ShoppingList core)