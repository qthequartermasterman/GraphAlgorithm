///*=============avl_tree.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 =============avl_tree.hpp================*/

#ifndef avl_tree_hpp
#define avl_tree_hpp

#include "binary_tree.hpp"

class avl_tree:public binary_tree{
private:
    Node* insert(int key, Node* leaf);
    Node* search(int key, Node* leaf);
    int find_min(Node* node);
    int get_balance(Node* node); //How unbalanced is the tree?
public:
    int find_min();
    void insert_key(int key);
};

#endif /* avl_tree_hpp */
