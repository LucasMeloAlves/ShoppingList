//
// Created by Lucas Melo Alves on 15/09/25.
//

#include "Category.h"

Category::Category(const std::string& name) : name(name) {}
// Getter e Setter
const std::string& Category::getName() const { return name; }
void Category::setName(const std::string& name) { this->name = name; }