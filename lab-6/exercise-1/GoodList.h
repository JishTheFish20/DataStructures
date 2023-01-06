#ifndef GOODLIST_H
#define GOODLIST_H

#include <cstdint>
#include <ostream>

struct GoodList{
    int** data;      // Pointer to the start of the data storage
    int dataCapacity; 
    int dataCount;      
    int count;
    int capacity;

    GoodList(){
        dataCapacity = 2;
        dataCount = 0;
        capacity = 1;               // An ArrayList always has room for at least one more element (initial capacity is 1)
        count = 0;                  // There are no elements stored at construction time
        data = new int*[dataCapacity];   // Allocate enough space on the heap 
        data[dataCount] = new int[capacity];
    }

    void append(int value){
           data[dataCount][count] = value; //adds new value 
           count++; //increases count to show how many values there are

        
        if(count == capacity){ //if the current pointer is full then run
            count = 0;
            capacity = capacity*2; //increase capacity by 2 fold

            dataCount++; //we need more room in our data** so we will create a new pointer

            if(dataCount == dataCapacity){ //if our data** space is filled then we will want to expand it
                dataCapacity = dataCapacity*2; //expand the data** space by 2 fold
                int** dataTemp = new int*[dataCapacity]; //create a new ** with increased space
                for(int x = 0; x < dataCount; x++){ //add the info of all old pointers to new **
                   dataTemp[x] =  data[x]; 
                }
                delete[] data; //deallocate old **

                data = dataTemp; //have old ** point to new **
            }

            data[dataCount] = new int[capacity];// 
        }
    }

    int& operator[](int index){
        return data[dataCount][index-1];
    }

    ~GoodList(){
         delete[] data;      // Just release the memory we are currently occupying
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){

     for (int i = 0; i < gl.dataCount; i++){
         for(int j = 0; j < gl.count; j++){
             os << gl.data[gl.count][i] << " ";
         }
    }

    return os;
}

#endif