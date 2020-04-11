///*=============tree.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============tree.hpp================*/

#ifndef tree_hpp
#define tree_hpp


struct Node{
    int key_value;
    Node* left_child;
    Node* right_child;
    int height; //Used just for AVL trees
};

class tree{
protected:
    Node* root; //The root of the tree
    virtual void insert(int key, Node* leaf) = 0;
    virtual Node* search(int key, Node* leaf) = 0;
    void destroy_tree(Node* leaf);
    void print_prefix(Node* node);
    void print_postfix(Node* node);
    void print_infix(Node* node);
    
public:
    tree();
    ~tree();
    
    void insert_key(int key);
    Node* search_key(int key);
    void destroy_tree();
    void print_prefix();
    void print_postfix();
    void print_infix();
    virtual int find_min()=0;
    virtual int find_max()=0;
    
};
#endif /* tree_hpp */
