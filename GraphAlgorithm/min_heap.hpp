///*=============heap.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 =============heap.hpp================*/

#ifndef min_heap_hpp
#define min_heap_hpp

#include <vector>
//ALthough in theory a heap could be implemented as a tree, in practice this is fairly difficult, as there is not a fast way to find the correct, next open slot.


class min_heap{
private:
    std::vector<int> heap_array;
    int current_size;
    
    int parent(int);
    int left_child(int);
    int right_child(int);
    
    void swap(int* x, int* y); //swap two values in an array
    
public:
    void insert(int key);
    int search(int key); //Return the index of the value. Returns -1 if not present
    void print();
    int find_min();
    int find_max();
};

#endif /* min_heap_hpp */
