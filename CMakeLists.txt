cmake_minimum_required(VERSION 4.0)
project(ShoppingList)

set(CMAKE_CXX_STANDARD 17)

add_executable(ShoppingList main.cpp
        Category.cpp
        Category.h
        ShoppingList.cpp
        ShoppingList.h
        Observer.h
        Subject.h
        User.cpp
        User.h
        Item.cpp
        Item.h)
