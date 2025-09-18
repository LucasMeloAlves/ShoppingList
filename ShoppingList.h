//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_SHOPPINGLIST_H
#define SHOPPINGLIST_SHOPPINGLIST_H


// ShoppingList.h
#include <string>
#include <vector>
#include "Observer.h"
#include "Item.h"
#include "Subject.h"

class ShoppingList : public Subject {
private:
    std::string name;
    std::vector<Item> items;
    std::list<Observer*> observers;

public:
    ShoppingList(const std::string& n);

    std::string getName() const;
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void setQuantity(const std::string& itemName, int quantity);
    std::vector<Item>& getItems();
    void printItems() const;
    void setItemPurchased(const std::string& itemName, bool purchased);
    // gestione Observer
    void addObserver(Observer* obs) override;
    void removeObserver(Observer* obs) override;
    void notify() override;
    ~ShoppingList() override = default;
};

#endif //SHOPPINGLIST_SHOPPINGLIST_H