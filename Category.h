//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_CATEGORY_H
#define SHOPPINGLIST_CATEGORY_H


#include <string>

class Category {
private:
    std::string name;
public:
    Category(const std::string& name);
    std::string getName() const;
    void setName(const std::string& name);
};

#endif //SHOPPINGLIST_CATEGORY_H