// cs2211
// assignment 4
// James Wong
// 251297165
// jwong988
// Nov 13 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// Input: 	’in_name’: a string ends with ’\0’
//  		’in_num’: an integer
// Output: 	a Key,
// Effect: 	copy in_name to Key’s name
//  		set Key’s num to be in_num
Key key_construct(char *in_name, int in_num) {
	Key key;	
					
	key.name = strdup(in_name);
	key.num = in_num;
									
	return key;
}

// Input: 	’key1’ and ’key2’ are two Keys
// Output: 	if return value < 0, then key1 < key2,
//  		if return value = 0, then key1 = key2,
// 	 	if return value > 0, then key1 > key2,
// Note: 	use strcmp() to compare key1.name and key2.name
// 		if key1.name = key2.name, then compare key1.num with key2.num
int key_comp(Key key1, Key key2) {
	int nameCompare = strcmp(key1.name, key2.name);
	if (nameCompare < 0 || (nameCompare == 0 && key1.num < key2.num)) {
		    return -1;
	} else if (nameCompare > 0 || (nameCompare == 0 && key1.num > key2.num)) {
		    return 1;
	} else {
		    return 0;
	}
}

// Input: ’key’: a Key
// Effect: key.num key.name are printed
void print_key(Key key) {
	printf("Key: id = %d, name = %s\n", key.num, key.name);
}

// Input: ’node’: a node
// Effect: node.key is printed and then the node.data is printed
void print_node(Node node) {
	printf("%-5d", node.key.num);
	printf("%-30s", node.key.name);
	printf("%-d\n", node.data);
}
