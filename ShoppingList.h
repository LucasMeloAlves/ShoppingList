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
    ShoppingList(const std::string& name = "Default List");
// operazioni sugli item
    void addItem(const Item& item);
    void removeItem(size_t index);
    void printItems() const;
    void clear();
    //getters
    const Item& getItem(size_t index) const;
    std::string getName() const;
    size_t getSize() const;
    size_t getPurchasedCount() const;
    //setters
    void setItemPurchased(const size_t index, bool purchased);
    void setQuantity(const std::string& itemName, int quantity);
    // gestione Observer
    void addObserver(Observer* obs) override;
    void removeObserver(Observer* obs) override;
    void notify() override;
    ~ShoppingList() override = default;
};

#endif //SHOPPINGLIST_SHOPPINGLIST_H