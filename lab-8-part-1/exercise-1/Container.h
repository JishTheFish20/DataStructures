#ifndef CONTAINER_H
#define CONTAINER_H

#include "ArrayList.h"
#include "LinkedList.h"

struct Container{

    ArrayList<bool> storage;
    int size;

    Container(){
        for(int i = 0; i < 10; i++){
            storage.append(false);
        }
    }

    Container (int N){
        size = N;
        for(int i = 0; i < size; i++){
           storage.append(false);
        }

    }

    

    void add(int key){
        storage[key] = true;
    }


    bool search(int key){
        return storage[key];
    }


};

#endif