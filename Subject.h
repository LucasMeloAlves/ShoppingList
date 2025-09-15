//
// Created by Lucas Melo Alves on 15/09/25.
//

#ifndef SHOPPINGLIST_SUBJECT_H
#define SHOPPINGLIST_SUBJECT_H
#include "Observer.h"
#include <vector>
class Subject
{
    virtual void addObserver(Observer* newObserver) = 0;
    virtual void removeObserver(Observer* deletedObserver) = 0;
    virtual void notify() = 0;
protected:
    virtual ~Subject() = default;

};


#endif //SHOPPINGLIST_SUBJECT_H