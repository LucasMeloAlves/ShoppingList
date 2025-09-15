//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_OBSERVER_H
#define SHOPPINGLIST_OBSERVER_H
#include <list>

class Observer
{
public:
    virtual void update(const std::string& listName) = 0;

protected:
    virtual ~Observer() = default;
};


#endif //SHOPPINGLIST_OBSERVER_H