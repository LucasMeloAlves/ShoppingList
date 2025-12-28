//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "ShoppingList.h"
#include <iostream>
#include <algorithm>

// Costruttore
ShoppingList::ShoppingList(const std::string& name) : name(name) {}

std::string ShoppingList::getName() const { return name; }

// ------------------ Gestione Item ------------------
void ShoppingList::addItem(const Item& item) {
    items.push_back(item);
    notify();
}

void ShoppingList::removeItem(const int& index) {
    if (index < 0 || index > items.size()) {
        throw std::out_of_range("Index out of range");
    }
        items.erase(items.begin() + index);
        notify();

}

void ShoppingList:: clear() {
    items.clear();
    notify();
}

void ShoppingList::setItemPurchased(const int index, bool purchased){
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

Item ShoppingList::getItem(int index)
{
    // controllo per indice fuori dai limiti
    if (index < 0 || index >= items.size()) {
        throw std::out_of_range("Index out of range");
    }
    return items[index];
}

size_t ShoppingList::getSize() const {
    return items.size();
}

void ShoppingList::printItems() const {
    std::cout << "Shopping List: " << name << std::endl;
    for (const auto& item : items) {
        item.print();
    }
}

size_t ShoppingList::getPurchasedCount() const{
    return std::count_if(items.begin(), items.end(),
                         [](const Item& item) { return item.isPurchased(); });
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
