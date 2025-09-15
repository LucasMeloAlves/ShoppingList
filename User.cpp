//
// Created by Lucas Melo Alves on 15/09/25.
//

// User.cpp

#include "User.h"

//costruttore
User::User(const std::string& name, std::string& username, std::string& email, int id)
    : name(name), username(username), email(email), id(id) {}

std::string User::getName() const {
    return name;
}

int User::getId() const {
    return id;
}

void User::setName(const std::string& newName) {
    name = newName;
}
User::~User() = default;
void User::update(const std::string& listName) {}




