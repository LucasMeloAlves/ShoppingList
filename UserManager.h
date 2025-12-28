//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_USERMANAGER_H
#define SHOPPINGLIST_USERMANAGER_H
#include "User.h"
#include <vector>

class UserManager {
private:
    // Deve essere un vector di shared_ptr per gestire più utenti
    std::vector<std::shared_ptr<User>> users;
public:
    // Nota: passiamo shared_ptr per coerenza con la gestione memoria
    void addUser(const std::shared_ptr<User>& user);
    void removeUser(const std::shared_ptr<User>& user);
    void printUsers() const;

    // Restituiamo shared_ptr per sicurezza, o User* se preferisci
    std::shared_ptr<User> getUserById(int id) const;
};

#endif //SHOPPINGLIST_USERMANAGER_H