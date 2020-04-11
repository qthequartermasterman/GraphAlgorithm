///*=============tree.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============tree.cpp================*/

#include "tree.hpp"
#include <iostream>
tree::tree(){
    root = nullptr;
}

tree::~tree(){
    destroy_tree();
}



//Recursively destroy all the elements of the tree.
void tree::destroy_tree(Node* leaf){
    if (leaf != nullptr){
        destroy_tree(leaf->left_child);
        destroy_tree(leaf->right_child);
        delete leaf;
    }
}
void tree::destroy_tree(){
    destroy_tree(root);
}

//Tree Printing/Traversal


void tree::print_prefix(Node* node){
    if (node == nullptr){
        return;
    }

    std::cout << node->key_value << " "; //Print the node's value
    print_prefix(node->left_child); //Print the left subtree
    print_prefix(node->right_child); //Print the right subtree

}
void tree::print_prefix(){
    print_prefix(root);
}

void tree::print_postfix(Node* node){
    if (node == nullptr){
        return;
    }
    print_postfix(node->left_child); //Print the left subtree
    print_postfix(node->right_child); //Print the right subtree
    std::cout << node->key_value << " "; //Print the node's value

}
void tree::print_postfix(){
    print_postfix(root);
}

void tree::print_infix(Node* node){
    if (node == nullptr){
        return;
    }
    print_infix(node->left_child); //Print the left subtree
    std::cout << node->key_value << " "; //Print the node's value
    print_infix(node->right_child); //Print the right subtree
}
void tree::print_infix(){
    print_infix(root);
}





//Insert/ Search
void tree::insert_key(int key){
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

Node* tree::search_key(int key){
    return search(key, root);
}
