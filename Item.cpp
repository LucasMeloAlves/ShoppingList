
#include "Item.h"
#include <iostream>

// Costruttore
Item::Item(const std::string& n, Category* c, int q, bool p)
    : name(n), category(c), quantity(q), purchased(p) {}

// Getter
std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
bool Item::isPurchased() const { return purchased; }
Category* Item::getCategory() const { return category; }
void Item::print() const {
    std::cout << "- " << name
              << " | Category: " << (category ? category->getName() : "None")
              << " | Quantity: " << quantity
              << " | Purchased: " << (purchased ? "Yes" : "No") << std::endl;
}
// Setter
void Item::setQuantity(int q)
{// Controllo per quantità negativa
    if (q < 0) {
        throw std::invalid_argument("Quantity cannot be negative");
    }
    quantity = q;
}
void Item::setPurchased(bool p) { purchased = p; }
void Item::setName(const std::string& n) { name = n; }
void Item::setCategory(Category* c) { category = c; }
