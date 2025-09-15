//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_USER_H
#define SHOPPINGLIST_USER_H
#include "Observer.h"
#include <string>

class User : public Observer {
private:
    std::string name;
    std::string username;
    std::string email;
    int id;
public:
    User(const std::string& name,std::string& username, std::string& email, int id);
    std::string getName() const;
    std::string getEmail() const;
    int getId() const;

    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);

    // implementazione dell'Observer
    void update(const std::string& listName) override;
    ~User() override;
};

#endif //SHOPPINGLIST_USER_H