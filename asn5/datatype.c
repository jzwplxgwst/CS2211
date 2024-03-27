// CS2211a 2023, Section 1
// Assignment 5
// James Wong
// 251297165
// jwong988
// Nov 23 2023

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "datatype.h"

// Input: nothing
// Output: a new key
// Effect: create and initialize a key with dynamic memory allocaiton
Key key_ini() {
	Key newKey = (Key)malloc(sizeof(Key_struct));	// function to create and initialize a Key with dynamic memory allocation

	if (newKey != NULL) {
		newKey -> key1 = strdup("default_key1");	// initialize to null
		newKey -> key2 = 0;	// initialize to a default value
	}

	return newKey;
}

// Input: three key values
// Output: a copy string and set integer
// Effect: set the key values with dynamic memory allocation
void key_set(Key key, Key1 key1, Key2 key2) {
	free(key->key1);	// free ant existing key1 string
	key->key1 = strdup(key1);	// allocate memory for key1 and copy the provided string
	free(key->key1);
	key->key2 = key2;	// set the value of key2
}

// Input: Two keys
// Output: compare value
// Effect: compare two keys
int key_comp(Key key1, Key key2) {
	int key1Compare = strcmp(key1->key1, key2->key1);	// compare key1->key1 and key2->key1 using strcmp

	if (key1Compare == 0) {
		return key1->key2 - key2->key2;	// retyrn if they are the same
	} else {
		return key1Compare;
	}
}

// Input: A key
// Output: nothing
// Effect: print key1 -> key2
void key_print1(Key key) {
	printf("key1 -> %s, key2 -> %d\n", key->key1, key->key2);
}

// Input: A key
// Output: nothing
// Effect: print key2 -> key1
void key_print2(Key key) {
	if (key != NULL) {
		printf("key2 -> %d, key1 -> %s\n", key->key2, key->key1);
	}
}

// Input: a key
// Output: nothing
// Effect: free memory allocated for a key
void key_free(Key key) {
	free(key);		// free the key structure
}

// Input: nothing
// Output: a new data variable 
// Effect: create and initialize a data with dynamic memory allocation
Data data_ini() {
	float* newData = (float*)malloc(sizeof(float));

	if (newData != NULL) {
		*newData = 0.0;	// initialize to a default value
	
		return newData;
	} else {
		printf("Error: Memory allocation failed\n");
		return NULL;
	}
}

// Input: a data amd a float
// Output: Nothing
// Effect: set data values
void data_set(Data data, float intdata) {
	if (data != NULL) {
		*data = intdata;
	} else {
		printf("error: Data is NULL\n");
	}
}

// Input: Data
// Output: Nothing
// Effect: print a data
void data_print(Data data) {
	printf("intdata -> %f\n", data);
}

// Input: Data
// Output: nothing
// Effect: free memory allocated for a data
void data_free(Data data) {
	free(data);	// free the data structure
}


