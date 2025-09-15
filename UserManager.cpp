//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "UserManager.h"
#include <algorithm>
#include <iostream>

void UserManager::addUser(User* user) {
    users.push_back(user);
}

void UserManager::removeUser(User* user) {
    users.remove(user);
}
User* UserManager::getUserById(int id) const {
    auto it = std::find_if(users.begin(), users.end(), [id](User* user) {
        return user->getId() == id;
    });
    return (it != users.end()) ? *it : nullptr;
}

void UserManager::printUsers() const {
    for (const auto& user : users) {
        std::cout << "User ID: " << user->getId() << ", Name: " << user->getName() << std::endl;
    }
}