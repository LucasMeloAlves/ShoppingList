//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_USER_H
#define SHOPPINGLIST_USER_H
#include "Observer.h"
#include "ShoppingList.h"
#include <string>

class User : public Observer {
private:
    std::string name;
    std::string username;
    std::string email;
    int id;
    std::vector<ShoppingList*> shoppingLists; // vettore di liste della spesa
public:

    User(const std::string& name, const std::string& username, const std::string& email, int id);

    std::string getName() const;
    std::string getEmail() const;
    int getId() const;

    //aggiugni lista e rimuovi lista
    void addShoppingList(ShoppingList* list);
    void removeShoppingList(ShoppingList* list);
    void printShoppingLists() const;
    const std::vector<ShoppingList*>& getShoppingLists() const;


    void setName(const std::string& newName);
    void setEmail(const std::string& newEmail);

    // implementazione dell'Observer
    void update(const std::string& listName) override;
    ~User() override;
};

#endif //SHOPPINGLIST_USER_H