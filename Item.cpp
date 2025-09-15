
#include "Item.h"
#include <iostream>

// Costruttore
Item::Item(const std::string& n, Category* c, int q, bool p, float price)
    : name(n), category(c), quantity(q), purchased(p), price(price) {}

// Getter
std::string Item::getName() const { return name; }
int Item::getQuantity() const { return quantity; }
bool Item::isPurchased() const { return purchased; }
Category* Item::getCategory() const { return category; }
float Item::getPrice() const { return price; }

// Setter
void Item::setQuantity(int q) { quantity = q; }
void Item::setPurchased(bool p) { purchased = p; }

