///*=============binary_tree.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/9/20
 EMAIL:         andrewsansom@my.unt.edu
 =============binary_tree.hpp================*/

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>

struct Node{
    int key_value;
    Node* left_child;
    Node* right_child;
};


class binary_tree{
private:
    Node* root; //The root of the tree
    
    void insert(int key, Node* leaf);
    Node* search(int key, Node* leaf);
    void destroy_tree(Node* leaf);
    
public:
    binary_tree();
    ~binary_tree();
    
    void insert(int key);
    Node* search(int key);
    void destroy_tree();
    
    
};

#endif /* binary_tree_hpp */
