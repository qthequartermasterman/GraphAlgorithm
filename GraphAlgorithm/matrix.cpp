///*=============matrix.cpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============matrix.cpp================*/

#include "matrix.hpp"
#include <iostream>

Matrix subtract_matrices(Matrix a, Matrix b){
    Matrix blarg(a.size(), std::vector<int>(a[0].size(),0) );
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a[0].size(); j++){
            blarg[i][j] = a[i][j] - b[i][j];
        }
    }
    return blarg;
}

void print_matrix(Matrix mat){
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
