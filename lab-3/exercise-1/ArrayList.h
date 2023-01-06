// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <ostream>

struct ArrayList{
    int* data;      // Pointer to the start of the data storage
    int capacity;   // The number of elements that we can currently store
    int count;      // The number of elements we have currently stored. 
                    // This is also the index of the first available storage space

    ArrayList(){
        capacity = 1;               // An ArrayList always has room for at least one more element (initial capacity is 1)
        count = 0;                  // There are no elements stored at construction time
        data = new int[capacity];   // Allocate enough space on the heap
    }

    void append(int value){
        data[count] = value;        // As per comments above, we always have space for 1 more, and count is the first available
        count++;                    // The count has increased by 1

        if (count == capacity){     // By storing the element above, we may no longer have space for at least one more
                                    // If that is the case, we must increase the capacity
            int oldCapacity = capacity;
            capacity *= 2;          // Make the capacity twice as big

            int* temp = new int[capacity];          // Allocate new space

            for (int i = 0; i < oldCapacity; i++){  // Copy elements from old space to new space
                temp[i] = data[i];
            }

            int* oldLocation = data;        // Keep track of where the original storage location was
            data = temp;                    // Point the data pointer to the new location
            delete[] oldLocation;           // Release previously occupied memory
        }
    }

    void prepend(int value){
        append(value);                      // First append the value, that will take care of increasing the capacity if it was necessary

        for (int i = count - 1; i > 0; i--){    // Now shift every element to the right by 1 space
            data[i] = data[i-1];                // This will leave position 0 available for us to put the new value there
        }

        data[0] = value;                        // Actually store the value in position 0
    }

    void removeFirst(){
        data[0] = 0; //remove first value
        int value = data[count-1]; //save last value
        removeLast(); //check for capacity change


        for (int i = 0; i < count-1; i++){    //shift all values left one
            data[i] = data[i+1];                
        }

        data[count-1] = value; //put the last value back

    }

    void removeLast(){
        data[count] = 0; //set last value to 0

        if(count != 0){
            data[count] = 0; //set last value to 0
            count--; //let count know capcity has decreased by one

            if (count < (capacity/2)){ //if we are taking up less then or equal to half of capacity shrink by a factor of two

                int oldCapacity = capacity; //store old capacity
                capacity /= 2; //divide capacity by two       

                int* temp = new int[capacity]; //create temporay array

                for (int i = 0; i < capacity; i++){ //transfer old array values to new array
                    temp[i] = data[i];
                }

                int* oldLocation = data; //keep track of original address
                data = temp; //point data to new array                   
                delete[] oldLocation; //delete old array          
            }
        }
        
    }

    ~ArrayList(){
        delete[] data;      // Just release the memory we are currently occupying
    }
};

std::ostream& operator<<(std::ostream& os, ArrayList& list){ // Print out the list on one line, separating the element by space
    for (int i = 0; i < list.count; i++){
        os << list.data[i] << " ";
    }

    return os;
}

#endif