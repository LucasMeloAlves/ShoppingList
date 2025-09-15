//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "ShoppingList.h"
#include "ShoppingList.h"
#include <iostream>
#include <algorithm>

// Costruttore
ShoppingList::ShoppingList(const std::string& n) : name(n) {}

std::string ShoppingList::getName() const { return name; }

// ------------------ Gestione Item ------------------
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();  // avviso gli osservatori
}

void ShoppingList::removeItem(const std::string& itemName) {
    items.erase(
        std::remove_if(items.begin(), items.end(),
            [&itemName](const Item& item) {
                return item.getName() == itemName;
            }),
        items.end()
    );
    notify(); // avviso gli osservatori
}



const std::vector<Item>& ShoppingList::getItems() const {
    return items;
}

// ------------------ Observer Pattern ------------------
void ShoppingList::addObserver(Observer* obs) {
    observers.push_back(obs);
}

void ShoppingList::removeObserver(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void ShoppingList::notify() {
    for (auto* obs : observers) {
        obs->update(name);
    }
}
