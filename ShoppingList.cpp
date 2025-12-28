//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "ShoppingList.h"
#include <iostream>
#include <algorithm>

// Costruttore
ShoppingList::ShoppingList(const std::string& name) : name(name) {}

std::string ShoppingList::getName() const { return name; }

// Operazioni sugli item
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(size_t index) {
    if (index > items.size()) {
        throw std::out_of_range("Index out of range");
    }
        items.erase(items.begin() + index);
        notify();

}

void ShoppingList:: clear() {
    items.clear();
    notify();
}

void ShoppingList::printItems() const {
    std::cout << "Shopping List: " << name << std::endl;
    for (const auto& item : items) {
        item.print();
    }
}
// Setters
void ShoppingList::setItemPurchased(size_t index, bool purchased){
    items[index].setPurchased(purchased);
    notify();
}
void ShoppingList::setQuantity(const std::string& itemName, int quantity)
{
    auto it = std::find_if(items.begin(), items.end(),
        [&itemName](const Item& item) {
            return item.getName() == itemName;
        });
    if (it != items.end()) {
        it->setQuantity(quantity);
        notify();
    }
}
// Getters
// Versione per leggere (non modifica la lista)
const Item& ShoppingList::getItem(size_t index) const {
    return items.at(index);
}

size_t ShoppingList::getSize() const {
    return items.size();
}

size_t ShoppingList::getPurchasedCount() const{
    return std::count_if(items.begin(), items.end(),
                         [](const Item& item) { return item.isPurchased(); });
}

// Implementazione observer
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
