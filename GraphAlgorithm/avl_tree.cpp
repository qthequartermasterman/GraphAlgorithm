///*=============avl_tree.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 =============avl_tree.cpp================*/

#include "avl_tree.hpp"
#include <algorithm>
#include <iostream>

// Get Balance factor of node N
int avl_tree::get_balance(Node *node)
{
    if (node == nullptr){
        return 0;
    }
    return height(node->left_child) - height(node->right_child);
}


Node* avl_tree::insert(int key, Node *leaf){
    // Step 1: standard Binary Search Tree insert
    //This is broken for some reason. I'll run it manually instead
    //Node* new_node = binary_tree::insert(key, leaf);
    //new_node->height = 1;
    print_prefix(); std::cout << std::endl;
    if (leaf == nullptr){
        print_prefix();std::cout << "Before new pointer" <<  std::endl;
        Node *node = new Node();
        node->key_value = key;
        node->left_child = nullptr;
        node->right_child = nullptr;
        node->height = 1;
        return node;
    }
    if (key <= leaf->key_value){
        print_prefix();std::cout << "Before new left" <<  std::endl;
        leaf->left_child = insert(key, leaf->left_child);
        print_prefix();std::cout << "after new left" <<  std::endl;
    } else{
        print_prefix();std::cout << "Before new right" <<  std::endl;
        leaf->right_child = insert(key, leaf->right_child);
        print_prefix();std::cout << "after new right" <<  std::endl;
    }
    
    
    //Step 2:Update the height of ancestor node
    leaf->height = 1 + std::max(height(leaf->left_child), height(leaf->right_child));
    
    //Step 3: Check the balance of the branch
    int balance = get_balance(leaf);
    
    //Step 4: Fix balance if needed
    //right-heavy
    if (balance < -1){
        if(key < leaf->right_child->key_value){
            leaf->right_child = rotate_right(leaf->right_child);print_prefix(); std::cout << "After after rotate right" <<  std::endl;
            Node* blarg = rotate_left(leaf);print_prefix();std::cout << "rotate left After rotate right" <<  std::endl;
            return blarg;
        } else {
            return rotate_left(leaf);
        }
    } else if(balance > 1){ //left heavy
        if (key < leaf->left_child->key_value){
            return rotate_right(leaf);
        } else {
            leaf->left_child = rotate_left(leaf->left_child);
            return rotate_right(leaf);
        }
    }
    
    //Return the unchanged node pointer if applicable
    print_prefix(); std::cout << std::endl;
    return leaf;
}

void avl_tree::insert_key(int key){
    if (root != nullptr){
        //If the tree isn't empty, insert it onto the root
        root = insert(key, root);
    } else {
        //Otherwise start the tree
        root = new Node;
        root->key_value = key;
        root->left_child = nullptr;
        root->right_child = nullptr;
    }
}


//Search functions
Node* avl_tree::search(int key, Node* leaf){
    return NULL;
}

int avl_tree::find_min(Node* node){
    if (node->left_child){ //If there is a right child, find the max on that subtree
        return find_min(node->left_child);
    } else {
        return node->key_value;
    }
}

int avl_tree::find_min(){
    return find_min(root);
}
