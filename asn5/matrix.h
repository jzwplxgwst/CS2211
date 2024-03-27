// CS2211a 2023, Section 1
// // Assignment 5
// // James Wong
// // 251297165
// // jwong988
// // Nov 23 2023

#include "bstree.h"

typedef BStree Matrix;
typedef Key1 Index1;
typedef Key2 Index2;
typedef float Value;

Matrix matrix_construction(void);
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2);
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2);
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);
// Function to create a key for the matrix
Key create_key(Index1 index1, Index2 index2);

