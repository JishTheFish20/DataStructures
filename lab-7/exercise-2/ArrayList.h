// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
private:
    T* data;
    int capacity;
    int count;

// Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }

public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    void swap(int a, int b){ //swaps two index's
       int temp = data[a];
       data[a] = data[b];
       data[b] = temp;
    }

    void insertion_sort(){
        for(int i = 0; i < count; i++){ // splits sorted list and unsorted
            for(int j = i; j > 0; j--){ //places index from unsorted list in sorted list
                if(data[j] < data[j-1]){
                    swap(j,j-1); //swaps until unsorted index is in correct position
                }
            }
        }
    }

    void add(T value){
        append(value);
        insertion_sort();
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    bool search(const T& value){
        return binary_search(value);
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}

#endif