//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "ShoppingList.h"
#include <iostream>

// Costruttore
ShoppingList::ShoppingList(const std::string& n) : name(n) {}

std::string ShoppingList::getName() const { return name; }

// ------------------ Gestione Item ------------------
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(const std::string& itemName) {
    items.remove_if([&itemName](const Item& item) {
        return item.getName() == itemName;
    });
    notify();
}

const std::list<Item>& ShoppingList::getItems() const {
    return items;
}

// ------------------ Observer Pattern ------------------
void ShoppingList::addObserver(Observer* obs) {
    observers.push_back(obs);
}

void ShoppingList::removeObserver(Observer* obs) {
    observers.remove(obs);
}

void ShoppingList::notify() {
    for (auto* obs : observers) {
        obs->update(name);
    }
}
