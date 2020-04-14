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

#include "tree.hpp"

class binary_tree : public tree{
private:
    Node* search(int key, Node* leaf);
    int find_max(Node* node);
protected:
    Node* insert(int key, Node* leaf);
    Node* rotate_right(Node* y);
    Node* rotate_left(Node* x);

public:
    int find_min();
    int find_max();

    
};

#endif /* binary_tree_hpp */
