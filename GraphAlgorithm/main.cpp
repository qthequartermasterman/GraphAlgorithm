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
    Matrix adjacency_matrix = {{0,0,0,0,0,3},{0,4,0,0,0,0},{0,0,2,0,2,1},{0,0,0,0,0,1},{0,0,2,0,0,1},{3,0,1,1,1,0}};
    
    adjacency_graph graph;
    graph.set_node_values({3,2,1,6,7,1});
    graph.set_adjacency_matrix(adjacency_matrix);
    graph.print();
    std::cout << "Degree Matrix:" << std::endl;
    print_matrix(graph.get_degree_matrix());
    std::cout << "Laplacian Matrix:" << std::endl;
    print_matrix(graph.get_laplacian_matrix());
    
    std::cout << "Traverse a DFS from index 0 \t"; graph.depth_first_search(0); std::cout << std::endl;
    std::cout << "Can we find 3?\t" << graph.depth_first_search(3, 0) <<std::endl;
    std::cout << "Can we find 7?\t" << graph.depth_first_search(7, 0) <<std::endl;
    std::cout << "Can we find 10?\t" << graph.depth_first_search(10, 0) <<std::endl;
    std::cout << "Traverse a BFS from index 0 \t"; graph.breadth_first_search(0); std::cout << std::endl;
    std::cout << "Can we find 3 with a BFS?\t" << graph.breadth_first_search(10, 0) <<std::endl;
    
    //std::cout << graph.list_search(3) << graph.list_search(39) << std::endl;
    return 0;
}
