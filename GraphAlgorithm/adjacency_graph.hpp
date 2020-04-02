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


class adjacency_graph{
    //A graph stored and defined using an adjacency matrix allows us to borrow tools from linear algrebra.
    //It also generalizes easily for weighted (un)directed graphs or multigraphs
private:
    std::vector< std::vector<int> > adjacency_matrix;
public:
    std::vector< std::vector<int> > get_adjacency_matrix();
    void set_adjacency_matrix(std::vector< std::vector<int> > matrix);
    
    std::vector< std::vector<int> > get_degree_matrix(); //Returns the matrix where the main diaganol is the degree of each node
    std::vector< std::vector<int> > get_laplacian_matrix(); //L = D-A, where D is the degree matrix and A is adjacency matrix. This is useful to certain graph analysis techniques, by borrowing techniques from linear algebra
    
    bool depth_first_search(int value_to_find, int starting_x, int starting_y); //Finds value_to_find in graph using a depth first search. Returns true if the element is found. Returns false otherwise
    bool breadth_first_search(int value_to_find, int starting_x, int starting_y);//Finds value_to_find in graph using a breadth first search. Returns true if the element is found. Returns false otherwise
    
    void topological_sort();
    void prims_algorithm();
    void kruskals_algorithm();
    void dijkstras_algorithm();
    
};

#endif /* adjacency_graph_hpp */