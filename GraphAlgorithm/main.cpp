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
    Matrix adjacency_matrix = {{1,0,1},{0,1,1},{1,1,0}};
    
    adjacency_graph graph;
    graph.set_node_values({3,2,1});
    graph.set_adjacency_matrix(adjacency_matrix);
    graph.print();
    
    print_matrix(graph.get_degree_matrix());
    print_matrix(graph.get_laplacian_matrix());
    return 0;
}
