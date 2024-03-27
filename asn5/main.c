// CS2211a 2023, Section 1
// // Assignment 5
// // James Wong
// // 251297165
// // jwong988
// // Nov 23 2023

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main() {
	// 1. create a new matricx
	Matrix matrix = matrix_construction();

	// 2. read from stdin, or redirect from a file, sequence of integer string pair (i.e. an integer
	// and then a string, possibly with spaces, per line) and then calculate occurrences of
	// each integer string pair read using the Matrix created.
	// – when input from keyboard, use Ctrl+D to terminate input.
	// – use the return value of scanf() to determine the end of input
	int integerValue;
	char stringValue[256];

	while (scanf("%d %255s", &integerValue, stringValue) == 2) {
		printf("sdsdf");

		char* index1 = (char*)&integerValue;
		unsigned long index2 = (unsigned long)&stringValue;

		matrix_set(matrix, index1,(int)index2, *matrix_get(matrix, index1, (int)index2) + 1.0);
	}

	// 3. Print the data in the matrix
	matrix_list(matrix);	

	// 4. Free all allocated memory spaces for the Matrix
	matrix_destruction(matrix);

	return 0;
}
