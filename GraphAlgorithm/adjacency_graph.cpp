/*=============adjacency_graph.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 =============adjacency_graph.cpp================*/

#include "adjacency_graph.hpp"
#include <iostream>
#include <queue>



/*Getters and Setters*/
Matrix adjacency_graph::get_adjacency_matrix(){
    return adjacency_matrix;
}
                                                  
void adjacency_graph::set_adjacency_matrix(Matrix matrix){
    adjacency_matrix = matrix;
}
std::vector<int> adjacency_graph::get_node_values(){return node_values;}
void adjacency_graph::set_node_values(std::vector<int> list){node_values = list;}
//void adjacency_graph::add_node(int value){node_values.push_back(value);}
//void adjacency_graph::delete_node(int value){}

/*IO functions*/
void adjacency_graph::print(){
    std::cout << "Nodes:" << std::endl;
    for (int i = 0; i < node_values.size(); i++){
        std::cout << node_values[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Adjancency Matrix:" << std::endl;
    print_matrix(adjacency_matrix);
}



/* Graph functions*/
Matrix adjacency_graph::get_degree_matrix(){
    int number_of_rows = (int) adjacency_matrix.size();
    int number_of_columns = (int) adjacency_matrix[0].size();
    //Create a degree matrix of zeros in the same shape as the adjacency matrix
    Matrix degree_matrix (number_of_rows,std::vector<int>(number_of_columns, 0) );
    
    for (int i = 0; i < adjacency_matrix.size(); i++){
        int running_total = 0;
        for (int j = 0; j < adjacency_matrix[0].size(); j++){
            running_total += adjacency_matrix[i][j]; //If an node is adjacent, then we add its edge to the running total
        }
        degree_matrix[i][i] = running_total; //Set the diaganol of the i-th row/column as the degree
    }
    return degree_matrix;
} //Returns the matrix where the main diaganol is the degree of each node

                                                  
Matrix adjacency_graph::get_laplacian_matrix(){
    return subtract_matrices(get_degree_matrix(), adjacency_matrix);
} //L = D-A, where D is the degree matrix and A is adjacency matrix. This is useful to certain graph analysis techniques, by borrowing techniques from linear algebra


bool adjacency_graph::list_search(int value_to_find){
    for (int i = 0; i < node_values.size(); i++){
        if (node_values[i] == value_to_find){
            return true;
        }
    }
    return false;
} //checks if value is in a list of all values

std::list<int> adjacency_graph::get_nodes_adjacent_to_node(int node){
    std::list<int> adjacent_nodes;
    for (int i = 0; i < node_values.size(); i++){
        if (adjacency_matrix[node][i]){
            adjacent_nodes.push_back(i);
        }
    }
    return adjacent_nodes;
}






/* Depth First Search */
void adjacency_graph::depth_first_search_util(int node, bool visited[]){
    //Mark the current node as visited, then print it
    visited[node] = true;
    std::cout << node << " ";
    //Now check all the adjacent nodes
    std::list<int>::iterator i;
    std::list<int> list_of_adjacent_nodes = get_nodes_adjacent_to_node(node);
    for (i = list_of_adjacent_nodes.begin(); i != list_of_adjacent_nodes.end(); i++){
        if (!visited[*i]){ //If we haven't been there, try that place first before moving on
            depth_first_search_util(*i, visited);
        }
    }
} //Recursive function used to implement the depth-first-search

bool adjacency_graph::depth_first_search_util(int node, bool visited[], int value_to_find){
    //Mark the current node as visited, then print it
    visited[node] = true;
    std::cout << node << " ";
    //Is this the node we want?
    if (node_values[node] == value_to_find){
        return true;
    }
    //Now check all the adjacent nodes
    std::list<int>::iterator i;
    std::list<int> list_of_adjacent_nodes = get_nodes_adjacent_to_node(node);
    for (i = list_of_adjacent_nodes.begin(); i != list_of_adjacent_nodes.end(); i++){
        if (!visited[*i]){ //If we haven't been there, try that place first before moving on
            bool result = depth_first_search_util(*i, visited, value_to_find);
            if (result){
                return true;
            }
        }
    }
    return false;
}


void adjacency_graph::depth_first_search(int starting_node){
    // Create a bool array indicating that we haven't visited any nodes yet
    bool *visited = new bool[node_values.size()];
    for (int i = 0; i < node_values.size(); i++)
        visited[i] = false;
    //Start the recursive search at starting_node
    depth_first_search_util(starting_node, visited);
    std::cout << std::endl;
} //Prints all nodes visited in graph using a depth first search.


bool adjacency_graph::depth_first_search(int value_to_find, int starting_node){
    // Create a bool array indicating that we haven't visited any nodes yet
    bool *visited = new bool[node_values.size()];
    for (int i = 0; i < node_values.size(); i++)
        visited[i] = false;
    //Start the recursive search at starting_node
    bool found_value = depth_first_search_util(starting_node, visited, value_to_find);
    std::cout << std::endl;
    return found_value;
} //Finds value_to_find in graph using a depth first search. Returns true if the element is found. Returns false otherwise






/*Breadth First Search*/
bool adjacency_graph::breadth_first_search(int value_to_find, int starting_node){
    
    
    return false;
} //Finds value_to_find in graph using a breadth first search. Returns true if the element is found. Returns false otherwise

void adjacency_graph::breadth_first_search(int starting_node){
    // Mark all the vertices as not visited
    int graph_size = (int) node_values.size();
    bool *visited = new bool[graph_size];
    for(int i = 0; i < graph_size; i++){
        visited[i] = false;
    }
    // Create a queue for the breadth first search
    std::queue<int> traversal_queue;
    // Note that we've visited the current node and put the node into the traversal_queue
    visited[starting_node] = true;
    traversal_queue.push(starting_node);

    //Add all the remaining nodes to the queue using a BFS
    while(!traversal_queue.empty())
    {
        // Dequeue a vertex from queue and print it
        int next_node = traversal_queue.front();
        // The iterator i will go over all the adjacent node indices
        std::list<int>::iterator i;
        std::cout << next_node << " ";
        traversal_queue.pop();
        std::list<int> list_of_adjacent_nodes = get_nodes_adjacent_to_node(next_node);
        
        // Add all the unvisited, adjacent nodes
        for (i = list_of_adjacent_nodes.begin(); i != list_of_adjacent_nodes.end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                traversal_queue.push(*i);
            }
        }
    }
}
