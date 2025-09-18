//
// Created by Lucas Melo Alves on 15/09/25.
//

// User.cpp

#include "User.h"
#include <iostream>

User::User(const std::string& name, const std::string& username, const std::string& email, int id)
    : name(name), username(username), email(email), id(id) {}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}

void User::setName(const std::string& newName) {
    name = newName;
}

const std::vector<ShoppingList*>& User::getShoppingLists() const {
    return shoppingLists;
}

void User::printShoppingLists() const
{
    std::cout << "Shopping Lists for User: " << name << std::endl;
    for (const auto& list : shoppingLists) {
        std::cout << "- " << list->getName() << std::endl;
    }
}

void User::addShoppingList(ShoppingList* list) {
    shoppingLists.push_back(list);
}

void User::removeShoppingList(ShoppingList* list) {
    shoppingLists.erase(
        std::remove(shoppingLists.begin(), shoppingLists.end(), list),
        shoppingLists.end()
    );
}
User::~User() = default;
void User::update(const std::string& listName) {}




