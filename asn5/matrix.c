// CS2211a 2023, Section 1
// // // Assignment 5
// // // James Wong
// // // 251297165
// // // jwong988
// // // Nov 23 2023

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "matrix.h"

// Input: void
// Output: a new matrix
// construct a matrix using BStree initialization
Matrix matrix_construction(void) {
	Matrix matrix = bstree_ini();
	return matrix;
}

// Input: a matrix, and two indices
// Output: 1 or 0
// check if a location is defined in the matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) {
	Data searchData = bstree_search(m, create_key(index1, index2));		// if (index1, index2) exist in the matrix

	return (searchData != NULL) ? 1: 0;	// location is defined or its not defined
}

// Input: a matrix and two indices
// Output: a pointer or null
// Effect: If location (index1, index2) is defined in Matrix m, then return a pointer to the associated value. Otherwise, return NULL.
const Value* matrix_get(Matrix m, Index1 index1, Index2 index2) {
	Key key = create_key(index1, index2);

	if (key != NULL) {
		Data searchData = bstree_search(m, key);	//check if the (index1, index2) pair exist in the matrix
		free(key);

		return searchData;	// return a pointer ro the associated value or return null
	} else {
		fprintf(stderr, "Error: Memory allocation failed for key\n");
		return NULL;
	}
}

// Input: a matrix, two indices and a value
// Output: Nothing
// EffectL: Assign value to Matrix m at location (index1, index2). If that location already has value, then overwrite.
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
	Key key = create_key(index1, index2);

	if (key != NULL) {
		Data searchData = bstree_search(m, key);

		if (searchData == NULL) {
			Data newData = (Data)malloc(sizeof(float));
			if (newData != NULL) {
				*newData = value;
				bstree_insert(m, key, newData);
			} else {
				fprintf(stderr, "Error: Memory allocation failed for newData\n");
			}
		} else {
			*searchData = value;
		}

		free(key);
	} else {
		        fprintf(stderr, "Error: Memory allocation failed for key\n");
	}
}

// Input: a matrix
// Output: nothing
// Effect: list indices and values in the matrix
void matrix_list(Matrix m) {
	printf("Matrix Contents:\n");
	bstree_traverse(m);
}

// Input: a matrix
// Output: nothing
// Effect: free allocated space for the matrix
void matrix_destruction(Matrix m) {
	bstree_free(m);
}

// Input: two indices
// Output: a key
// Effect: helper function to create a key for the matrix
Key create_key(Index1 index1, Index2 index2) {
	Key key = (Key)malloc(sizeof(Key_struct));
	if (key != NULL) {
		key->key1 = index1;
		key->key2 = index2;
	}

	return key;
}

