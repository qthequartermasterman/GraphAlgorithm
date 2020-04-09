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
    //Matrix weighted_undirected_matrix_with_loops = {{0,0,0,0,0,3},{0,4,0,0,0,0},{0,0,2,0,2,1},{0,0,0,0,0,1},{0,0,2,0,0,1},{3,0,1,1,1,0}};
    Matrix directed_acyclic_matrix = {{0,0,1,0,0,1},{0,0,0,0,1,1},{0,0,0,1,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
    Matrix weighted_undirected_matrix = { { 0, 2, 0, 6, 0 },
    { 2, 0, 3, 8, 5 },
    { 0, 3, 0, 0, 7 },
    { 6, 8, 0, 0, 9 },
    { 0, 5, 7, 9, 0 } };
    
    adjacency_graph graph;
    graph.set_node_values({0,1,2,3,4});
    graph.set_adjacency_matrix(weighted_undirected_matrix);
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
    std::cout << "Now we'll use Prim's algorithm to find a minimum spanning tree. \n"; graph.prims_algorithm(); std::cout << std::endl;
    
    std::cout << "Now we're going to perform a topological sort on this direct acyclic graph"<<std::endl;
    adjacency_graph acyclic_graph;
    acyclic_graph.set_node_values({0,1,2,3,4,5});
    acyclic_graph.set_adjacency_matrix(directed_acyclic_matrix);
    acyclic_graph.print();
    std::cout << "One Topological Sort: "; acyclic_graph.topological_sort(); std::cout << std::endl;
    
    return 0;
}
