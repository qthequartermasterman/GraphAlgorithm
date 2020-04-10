/*=============adjacency_graph.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 =============adjacency_graph.hpp================*/

#ifndef adjacency_graph_hpp
#define adjacency_graph_hpp

#include <stdio.h>
#include <vector>
#include "matrix.hpp"
#include <list>
#include <stack>


class adjacency_graph{
    //A graph stored and defined using an adjacency matrix allows us to borrow tools from linear algrebra.
    //It also generalizes easily for weighted (un)directed graphs or multigraphs
private:
    Matrix adjacency_matrix;
    std::vector<int> node_values;
    
    void depth_first_search_util(int node, bool visited[]); //Recursive function used to implement the depth-first-search
    bool depth_first_search_util(int node, bool visited[], int value_to_find);
    void topological_sort_util(int node, bool visited[], std::stack<int> &topological_stack);
    
    int find_minimum_distance_value(int distances[], bool mstSet[]);
    int find_kruskal_set(int i, int spanning_tree[]); //Finds the set of edges we have chosen connected to node i
    void kruskal_union(int i, int j, int spanning_tree[]); //Takes the union of two sets
    
    int find_min_distance_dijkstra(int distances[], bool sptSet[]);
public:
    Matrix get_adjacency_matrix();
    void set_adjacency_matrix(Matrix matrix);
    
    std::vector<int> get_node_values();
    void set_node_values(std::vector<int> list);
    //void add_node(int value);
    //void delete_node(int value);
    
    void print();
    
    Matrix get_degree_matrix(); //Returns the matrix where the main diaganol is the degree of each node
    Matrix get_laplacian_matrix(); //L = D-A, where D is the degree matrix and A is adjacency matrix. This is useful to certain graph analysis techniques, by borrowing techniques from linear algebra
    
    std::list<int> get_nodes_adjacent_to_node(int node);
    
    bool list_search(int value_to_find); //checks if value is in the matrix
    bool depth_first_search(int value_to_find, int starting_node); //Finds value_to_find in graph using a depth first search. Returns true if the element is found. Returns false otherwise
    void depth_first_search(int starting_node); //Prints all nodes visited in graph using a depth first search.
    bool breadth_first_search(int value_to_find, int starting_node);//Finds value_to_find in graph using a breadth first search. Returns true if the element is found. Returns false otherwise
    void breadth_first_search(int starting_node); //Prints all nodes visited in graph using a breadth first search.
    
    void topological_sort();
    void prims_algorithm();
    void kruskals_algorithm();
    void dijkstras_algorithm(int source_node);
    
};
#endif /* adjacency_graph_hpp */
