/*=============adjacency_graph.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 =============adjacency_graph.cpp================*/

#include "adjacency_graph.hpp"



Matrix adjacency_graph::get_adjacency_matrix(){
    return adjacency_matrix;
}
                                                  
void adjacency_graph::set_adjacency_matrix(Matrix matrix){
    adjacency_matrix = matrix;
}

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


bool matrix_search(int value_to_find){
    
    return false;
} //checks if value is in the matrix
bool adjacency_graph::depth_first_search(int value_to_find, int starting_x, int starting_y){
    
    return false;
} //Finds value_to_find in graph using a depth first search. Returns true if the element is found. Returns false otherwise

bool adjacency_graph::breadth_first_search(int value_to_find, int starting_x, int starting_y){
    return false;
} //Finds value_to_find in graph using a breadth first search. Returns true if the element is found. Returns false otherwise
