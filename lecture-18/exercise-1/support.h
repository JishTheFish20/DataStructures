#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include "BSTNode.h"

// Your 3 functions here here...
// Insert, Traverse, and Search...

BSTNode* insert(BSTNode* root, int value){
    if(root == nullptr){ // if tree dne then have root equal value
        root = new BSTNode(value);

    }else if(value >= root->data){// if value is > then root put node on right
        root->right = insert(root->right, value);

    }else{
        root->left = insert(root->left, value); //else if value < root put node on left
    }

    return root;
}

void traverse(BSTNode* root){
    if(root != nullptr){
        traverse(root->left);
        std::cout << root->data << std::endl;
        traverse(root->right);
    }
}

bool search(BSTNode* root, int value){
    if(root == nullptr){ //check if the root is null 
        std::cout << "Value Does not Exist" << std::endl;
         return false;

    }else{
         if(value == root->data){ //if value is equal to root return true
            std::cout << value << std::endl;
            return true;

         }else if(value > root->data){ // if value > root search right branch
            return search(root->right, value);

        }else{
            return search(root->left, value); // if value < root search left branch
        }
    }
}

#endif