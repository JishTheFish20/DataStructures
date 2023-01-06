// This file will contain part of your solution
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include "AbstractList.h"
#include "Node.h"

// Make the ArrayList struct conform to AbstractList

struct LinkedList : public AbstractList{
    Node* head;             // Keep a pointer to the head (first element) of the list

    LinkedList(){       
        head = nullptr;     // A null pointer for head means the list is empty
    }

    void prepend(int value){
        if (head == nullptr){           // If we currently have an empty list
            head = new Node(value);     // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value
            temp->next = head;              // Make the current head to be the next element of the newly created node
            head = temp;                    // Point the head to the newly created node
        }
    }

    void append(int value){
        if (head == nullptr){               // If we have an empty list
            head = new Node(value);         // Create a new node with the given value and make that the head
        }
        else{                               // If there are already elements in the list
            Node* temp = new Node(value);   // Make a new node with the given value

            Node* last = head;              // Find the last element in the list
            while (last->next != nullptr){  // That is the first element whose next pointer is null
                last = last->next;
            }

            last->next = temp;              // Make the next pointer of the last element point to the newly created node
        }
    }

    void removeFirst(){
        if (head != nullptr){//check if list is empty
            head = head->next; //set head to start at the second element
        }
    }

    void removeLast(){
        if((head != nullptr) && head->next != nullptr ){ //check if first is null and second is null
            Node* secondTolast = head;

            while(secondTolast->next->next != nullptr){  //check the pointer after the one your about to move to
                secondTolast = secondTolast->next; //move your pointer by one
            }
            secondTolast->next = nullptr; //tell the list before the nullptr to equal null
        }else{
            head = nullptr;
        }

    }

    ~LinkedList(){                  // We must release all the memory we are occupying, which is not necessarily one contiguous chunk
        Node* temp = head;          // Start at the head
        while (head != nullptr){    // As long as there are more elements
            head = head->next;      // release the head element and make its pointer point to the next element
            delete temp;
            temp = head;
        }
    }
};

std::ostream& operator<< (std::ostream& os, LinkedList& list){ // Print out the list on one line, separating elements by a space
    Node* current = list.head;
    while (current != nullptr){
        os << current->data << " ";
        current = current->next;
    }

    return os;
}


#endif