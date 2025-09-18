//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_USERMANAGER_H
#define SHOPPINGLIST_USERMANAGER_H
#include "User.h"
#include <vector>

class UserManager
{
private:
    std::vector<User*> users;
public:
    void addUser(User* user);
    void removeUser(User* user);
    User* getUserById(int id) const;
    void printUsers() const;
};


#endif //SHOPPINGLIST_USERMANAGER_H