///*=============pointer_graph.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 =============pointer_graph.hpp================*/

#ifndef pointer_graph_hpp
#define pointer_graph_hpp

#include <stdio.h>
#include <vector>

class Node{
private:
    int value;
    std::vector< Node* > edges;
    
public:
    int get_value();
    void set_value(int val);
    
    std::vector< Node* > get_edges();
    void add_edge(Node* node_to_add);
    void delete_edge(Node* node_to_delete);
    
    bool depth_first_search(int value_to_find, int starting_x, int starting_y); //Finds value_to_find in graph using a depth first search. Returns true if the element is found. Returns false otherwise
    bool breadth_first_search(int value_to_find, int starting_x, int starting_y);//Finds value_to_find in graph using a breadth first search. Returns true if the element is found. Returns false otherwise
    
    void topological_sort();
    void prims_algorithm();
    void kruskals_algorithm();
    void dijkstras_algorithm();
};

#endif /* pointer_graph_hpp */
