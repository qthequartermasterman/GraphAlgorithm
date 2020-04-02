///*=============main.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============main.cpp================*/

#include <iostream>
#include "matrix.hpp"
#include "adjacency_graph.hpp"


int main(int argc, const char * argv[]) {
    Matrix mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Matrix mat2 = {{9,9,9,9},{9,9,9,9},{9,9,9,9},{9,9,9,9}};
    
    adjacency_graph graph;
    graph.set_adjacency_matrix(mat);

    print_matrix(mat);
    print_matrix(subtract_matrices(mat2, mat));
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
