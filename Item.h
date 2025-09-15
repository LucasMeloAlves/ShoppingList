//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_ITEM_H
#define SHOPPINGLIST_ITEM_H

#include <string>
#include "Category.h"

class Item {
private:
    std::string name;
    Category* category;   // puntatore alla categoria
    float price;       // prezzo dell'articolo
    int quantity;
    bool purchased;

public:
    // Costruttore
    Item(const std::string& name, Category* category, int quantity = 1, bool purchased = false, float price=0.0f);

    // Getter
    std::string getName() const;
    int getQuantity() const;
    bool isPurchased() const;
    Category* getCategory() const;
    float getPrice() const;

    // Setter
    void setQuantity(int q);
    void setPurchased(bool p);

    // Utility
    void print() const;
};

#endif //SHOPPINGLIST_ITEM_H