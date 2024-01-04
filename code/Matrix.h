#ifndef _matrix_h_
#define _matrix_h_

#include "stdlib.h"
#include "struct_enum.h"

matrix matrix_init(int row,int col);
matrix matrix_plus(matrix left_matrix,matrix right_matrix);
matrix matrix_multiply(matrix left_matrix,matrix right_matrix);
matrix matrix_transposition(matrix input_matrix);
matrix Gaussian_elimination(matrix input_martrix);
void matrix_free(matrix m);

#endif
