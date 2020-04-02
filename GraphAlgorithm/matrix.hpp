///*=============matrix.hpp================*/
/*
 DESCRIPTION:   
 AUTHOR:        Andrew P. Sansom
 VERSION:       1.0.0
 VERSION DATE:  4/2/20
 EMAIL:         andrewsansom@my.unt.edu
 COURSE:        CSCE 1040
 =============matrix.hpp================*/

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <vector>

typedef std::vector< std::vector<int> > Matrix;

Matrix subtract_matrices(Matrix a, Matrix b);
void print_matrix(Matrix mat);

#endif /* matrix_hpp */
