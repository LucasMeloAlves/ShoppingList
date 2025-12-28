#include "UserManager.h"
#include <algorithm>
#include <iostream>

// Corretto: ora accetta uno shared_ptr come definito nell'header
void UserManager::addUser(const std::shared_ptr<User>& user) {
    if (user) {
        users.push_back(user);
    }
}

// Corretto: remove standard per smart pointers
void UserManager::removeUser(const std::shared_ptr<User>& user) {
    // std::remove funziona direttamente sugli shared_ptr confrontando gli indirizzi
    users.erase(std::remove(users.begin(), users.end(), user), users.end());
}

void UserManager::printUsers() const {
    for (const auto& u : users) {
        // Usiamo -> perché u è uno shared_ptr
        if (u) {
            std::cout << "User ID: " << u->getId()
                      << ", Name: " << u->getName() << std::endl;
        }
    }
}

// Corretto: restituisce uno shared_ptr invece di un User*
std::shared_ptr<User> UserManager::getUserById(int id) const {
    auto it = std::find_if(users.begin(), users.end(), [id](const std::shared_ptr<User>& u) {
        return u && u->getId() == id;
    });

    if (it != users.end()) {
        return *it; // Restituisce lo smart pointer trovato
    }
    return nullptr;
}