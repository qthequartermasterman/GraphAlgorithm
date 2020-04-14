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
#include "binary_tree.hpp"
#include "min_heap.hpp"
#include "avl_tree.hpp"


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
    std::cout << "Now we'll use Kruskal's algorithm to find a minimum spanning tree. \n"; graph.kruskals_algorithm(); std::cout << std::endl;
    std::cout << "Now we'll use Dijsktra's algorithm to find the shortest distance to each other node. \n"; graph.dijkstras_algorithm(0); std::cout << std::endl;
    
    std::cout << "Now we're going to perform a topological sort on this direct acyclic graph"<<std::endl;
    adjacency_graph acyclic_graph;
    acyclic_graph.set_node_values({0,1,2,3,4,5});
    acyclic_graph.set_adjacency_matrix(directed_acyclic_matrix);
    acyclic_graph.print();
    std::cout << "One Topological Sort: "; acyclic_graph.topological_sort(); std::cout << std::endl;
    
    std::cout << std::endl << std::endl << std::endl << std::endl << std::endl;
    std::cout << "Now let's do some tree stuff" << std::endl;
    int list_of_ints_to_insert_into_trees[] = {1,3,4,5,6,1,2,3,4,604,493,2039,382,324,765,236,854,12346,14,23,34};
    //Initialize the trees
    binary_tree bin_tree;
    min_heap heap;
    avl_tree avl;
    for (auto number : list_of_ints_to_insert_into_trees){
        bin_tree.insert_key(number);
        heap.insert(number);
        avl.insert_key(number);
    };
    
    std::cout << "Binary Search Tree" << std::endl;
    std::cout << "Prefix: "; bin_tree.print_prefix(); std::cout << std::endl;
    std::cout << "Infix: "; bin_tree.print_infix(); std::cout << std::endl;
    std::cout << "Postfix: "; bin_tree.print_postfix(); std::cout << std::endl<<std::endl;
    std::cout << "Min: " << bin_tree.find_min() << "\tMax: " << bin_tree.find_max() << std::endl;
    std::cout << std::endl;
    
    std::cout << "Heap" << std::endl;
    heap.print();
    std::cout << "Min: " << heap.find_min() << "\tMax: " << heap.find_max() << std::endl;
    std::cout << std::endl;
    
    std::cout << "AVL" << std::endl;
    std::cout << "Prefix: "; avl.print_prefix(); std::cout << std::endl;
    std::cout << "Infix: "; avl.print_infix(); std::cout << std::endl;
    std::cout << "Postfix: "; avl.print_postfix(); std::cout << std::endl<<std::endl;
    std::cout << "Min: " << avl.find_min() << "\tMax: " << avl.find_max() << std::endl;
    
    
    return 0;
}
