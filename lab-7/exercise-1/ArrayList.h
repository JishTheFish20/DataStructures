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

   void findMinPos(int pos){
       int min = pos;
       int i;
        for(i = min; i < count-1; i++){ //goes through each index
            if(data[min] > data[i+1]){ //if new index is less then current new min set new to min
                min = i+1;
            }
        }
        swap(pos, min);
   } 

   void swap(int a, int b){ //swaps two index's
       int temp = data[a];
       data[a] = data[b];
       data[b] = temp;
   }


    void selection_sort(){
       for(int i = 0; i < count; i++){ //finds the next minimum for each position
           findMinPos(i);
       }
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

    void quick_sort(){
        // Your code here
       qsort(0, count-1);
    }

    void qsort(int start, int end){
        // Your code here

        if(start < end){
            int p = partition(start, end);

            qsort(start, p-1);
            qsort(p+1, end);
        }
    }

    int partition(int start, int end){
        int pivot = data[start]; //have pivot be first index
        int pivotIndex = start;

        for(int i = start+1; i < count; i++){ //find position pivot needs to be in
            if(data[i] < pivot){
                pivotIndex++;
            }
        }
        swap(start, pivotIndex); //put pivot in correct index

        //sets arrows to the left and right of current array section
        int left = start;
        int right = end;

        //checks to see if arrows are in the same position
        while(left < pivotIndex && right > pivotIndex){
            while(data[left] < pivot){ //if value is in the correct side go next
                left++;
            }
            while(data[right] >= pivot){//if value is in the correct side go next
                right--;
            }

            if(left < pivotIndex && right > pivotIndex){//once two values are in the wrong side of pivot swap them
                swap(left, right);
            }
        }


        return pivotIndex; //give pivot index
    }


                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    ArrayList(const ArrayList<T>& other){
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    ArrayList<T>& operator=(const ArrayList<T>& other){
        T* oldData = data;
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
        delete[] oldData;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool operator==(const ArrayList<T>& other) const{
        if (count != other.count){
            return false;
        }

        for (int i = 0; i < count; i++){
            if(data[i] != other.data[i]){
                return false;
            }
        }
        return true;
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

    int size() const{
        return count;
    }

    bool search(const T& value){
        return binary_search(value);
    }

    void sort(int algo){
        if (algo == 1){
            selection_sort();
        }
        else if(algo == 2){
            insertion_sort();
        }
        else if (algo == 3){
            quick_sort();
        }
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list.get(i) << " ";
    }

    return os;
}

#endif