// Do not modify this file
#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

#include <ostream>
#include <string>
#include "ArrayList.h"
#include "LinkedList.h"
#include "AbstractList.h"

struct ListFactory{
    static AbstractList* create(std::string listName){
        if (listName == "ArrayList"){
            return new ArrayList();
        }else if(listName == "LinkedList"){
            return new LinkedList();
        }else{
            return nullptr;
        }
    }
};

// This allows us to print LinkedList and ArrayList objects
std::ostream& operator<<(std::ostream& os, AbstractList* list){
    if (typeid(*list).name() == typeid(LinkedList).name()){
        os << *((LinkedList*)list);
    }
    else if (typeid(*list).name() == typeid(ArrayList).name()){
        os << *((ArrayList*)list);
    }
    else{
        os << "Can't print this list";
    }

    return os;
}

#endif