#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <exception>

struct HashTable{
    ArrayList<LinkedList<int>> table;
    LinkedList<int> list;

    // You can declare more instance variables here
    int K;

    HashTable(){
        K = 10;
        // If you have more instance variables, init them here
        for(int i = 0; i < K; i++){
            table.append(list); //add linked list to each array index
        }
    }

    HashTable(int K){
        this->K = K;
        // If you have more instance variables, init them here
        for(int i = 0; i < K; i++){
            table.append(list); //add linked list to each array index
        }
    }

    void add(int value){
        table[(value%10)].append(value); //place value in linked list
    }

    bool search(int value){
        if(value < 0){
           return -1;
        }
        return table[(value%10)].search(value); //search for value in linked list
    }

    // You can declare other functions if needed

};

#endif