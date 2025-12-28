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
    int quantity;
    bool purchased;

public:
    // Costruttore
    Item(const std::string& name, Category* category, int quantity = 1, bool purchased = false);

    // Getter
    std::string getName() const;
    int getQuantity() const;
    bool isPurchased() const;
    Category* getCategory() const;

    // Setter
    void setQuantity(int q);
    void setPurchased(bool p);
    void setName(const std::string& n);
    void setCategory(Category* c);


    void print() const;
};

#endif //SHOPPINGLIST_ITEM_H