//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "ShoppingList.h"
#include <iostream>
#include <algorithm>

// Costruttore
ShoppingList::ShoppingList(const std::string& n) : name(n) {}

std::string ShoppingList::getName() const { return name; }

// ------------------ Gestione Item ------------------
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(const std::string& itemName) {
    items.erase(
        std::remove_if(items.begin(), items.end(),
            [&itemName](const Item& item) {
                return item.getName() == itemName;
            }),
        items.end()
    );
    notify();
}

const std::vector<Item>& ShoppingList::getItems() const {
    return items;
}

void ShoppingList::printItems() const {
    std::cout << "Shopping List: " << name << std::endl;
    for (const auto& item : items) {
        item.print();
    }
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
