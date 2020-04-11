///*=============binary_tree.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/9/20
 EMAIL:         andrewsansom@my.unt.edu
 =============binary_tree.cpp================*/

#include "binary_tree.hpp"
#include <iostream>

//Insert a key into the tree
void binary_tree::insert(int key, Node* leaf){
    if (key <= leaf->key_value){ //If the key is less the leaf, then traverse the left half
        if (leaf->left_child != nullptr){ //If there is already a left child, recursively insert it onto that branch
            insert(key, leaf->left_child);
        } else {
            //Otherwise, create a new node with the key and no children
            leaf->left_child = new Node;
            leaf->left_child->key_value=key;
            leaf->left_child->left_child=nullptr;
            leaf->left_child->right_child=nullptr;
        }
    } else if (key > leaf->key_value){//Otherwise traverse the right half
        if (leaf->right_child != nullptr){ //If there is already a right child, recursively insert
            insert(key, leaf->right_child);
        } else {
            //Otherwise, create a new node with the key and no children
            leaf->right_child = new Node;
            leaf->right_child->key_value=key;
            leaf->right_child->left_child=nullptr;
            leaf->right_child->right_child=nullptr;
        }
    }
}
//Search functions
Node* binary_tree::search(int key, Node* leaf){
    if (leaf != nullptr){ //If the node exists
        if (key==leaf->key_value){ //If the node has the desired value, return the node
            return leaf;
        } else if ( key < leaf->key_value){ //If the desired value is less, search the left subtree
            return search(key, leaf->left_child);
        } else {
            return search(key, leaf->right_child);//If the desired value is greater, search the right subtree
        }
    } else{
        return nullptr;
    }
}

int binary_tree::find_min(){
    return root->key_value;
}
//Recursive function. returns the value of the right most node
int binary_tree::find_max(Node* node){
    if (node->right_child){ //If there is a right child, find the max on that subtree
        return find_max(node->right_child);
    } else {
        return node->key_value;
    }
}
int binary_tree::find_max(){
    return find_max(root);
}

