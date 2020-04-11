///*=============min_heap.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/10/20
 EMAIL:         andrewsansom@my.unt.edu
 =============min_heap.cpp================*/

#include "min_heap.hpp"
#include <iostream>
#include <algorithm>
//Insert a key into the tree
int min_heap::parent(int x){return (int) x/2;};
int min_heap::left_child(int x){return 2*x + 1;};
int min_heap::right_child(int x){return 2*x + 2;};
void min_heap::swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void min_heap::insert(int key){
    //Insert new key at the end
    heap_array.push_back(key);
    int i = (int) heap_array.size() - 1; //The index of the far right on heap array.

    //fix the min_heap property
    while (i > 0 && heap_array[parent(i)] > heap_array[i]){ //Parent is bigger and we're not at the top
        swap(&heap_array[i], &heap_array[parent(i)]);
        i = parent(i); //Move the index to the inserted element to see if it still violates the min_heap property
    }
}

int min_heap::search(int key){
    for (int i =0; i < heap_array.size(); i++){
        if (heap_array[i] == key){
            return i;
        }
    }
    return -1;
}

void min_heap::print(){
    std::cout << "Heap: ";
    for (int element: heap_array){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int min_heap::find_min(){
    return heap_array[0];
}

int min_heap::find_max(){
    return *std::max_element(heap_array.begin(), heap_array.end());
}
