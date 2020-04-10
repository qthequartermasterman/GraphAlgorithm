///*=============binary_tree.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/9/20
 EMAIL:         andrewsansom@my.unt.edu
 =============binary_tree.cpp================*/

#include "binary_tree.hpp"

binary_tree::binary_tree(){
    root = nullptr;
}

binary_tree::~binary_tree(){
    destroy_tree();
}



//Recursively destroy all the elements of the tree.
void binary_tree::destroy_tree(Node* leaf){
    if (leaf != nullptr){
        destroy_tree(leaf->left_child);
        destroy_tree(leaf->right_child);
        delete leaf;
    }
}
void binary_tree::destroy_tree(){
    destroy_tree(root);
}

//Insert a key into the tree
void binary_tree::insert(int key, Node* leaf){
    if (key < leaf->key_value){ //If the key is less the leaf, then traverse the left half
        if (leaf->left_child != nullptr){ //If there is already a left child, recursively insert it onto that branch
            insert(key, leaf->left_child);
        } else {
            //Otherwise, create a new node with the key and no children
            leaf->left_child = new Node;
            leaf->left_child->key_value=key;
            leaf->left_child->left_child=nullptr;
            leaf->left_child->right_child=nullptr;
        }
    } else if (key >= leaf->key_value){//Otherwise traverse the right half
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

void binary_tree::insert(int key){
    if (root != nullptr){
        //If the tree isn't empty, insert it onto the root
        insert(key, root);
    } else {
        //Otherwise start the tree
        root = new Node;
        root->key_value = key;
        root->left_child = nullptr;
        root->right_child = nullptr;
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

Node* binary_tree::search(int key){
    return search(key, root);
}


