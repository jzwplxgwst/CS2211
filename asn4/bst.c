// cs2211
// // assignment 4
// // James Wong
// // 251297165
// // jwong988
// // Nov 13 2023

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int bstInsertRecursive(BStree bst, Key key, int pos);
void bstTraversalRecursive(BStree bst, int pos);

// Input: ’size’: size of an array
// Output: a BStree,
// Effect: allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned char array of size+1 for member is_free
// set all entries of is_free to 1
// set member size to ’size’;
BStree bstree_ini(int size) {
	BStree bst;
	bst.tree_nodes = malloc((size + 1) * sizeof(Node));
	bst.is_free = malloc((size + 1) * sizeof(char)); 
	bst.size = size;

	for(int i=0; i<size+1; i++) {
		*(bst.is_free + i) = 1;
	}

	return bst;
}

// Input: ’bst’: a binary search tree
// ’key’: a Key
// 'data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key key, int data) {
	Node node;
	node.key = key;
	node.data = data;

	int pos = bstInsertRecursive(bst, key, 1);

	if (pos >= 0 && bst.is_free[pos] == 1) {
		    bst.tree_nodes[pos] = node;
		        bst.is_free[pos] = 0;
	} else {
		printf("array out of bounds");
	}
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
	bstTraversalRecursive(bst, 1);		 
}

// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {	
	free(bst.tree_nodes);
	free(bst.is_free);
	bst.tree_nodes = NULL;
	bst.is_free = NULL;
}


// recursive function to get the key in the binary searcg tree
int bstInsertRecursive(BStree bst, Key key, int pos) {

	if ((pos * 2 <= bst.size) && (pos * 2 + 1 <= bst.size) && (*(bst.is_free + pos) != 1) && (pos < bst.size)) {
		Node hold = *(bst.tree_nodes + pos);
		int value = key_comp(key, hold.key);    // Compare with the current node
		
		if (value < 0) {
			return bstInsertRecursive(bst, key, 2 * pos);      // Call the recursive function
		} else if (value > 0) {
			return bstInsertRecursive(bst, key, 2 * pos + 1);  // Call the recursive function
		} else if (value == 0) {
			return pos;    // Key already exists at this position
		}
	}
	
	return pos;    // Return the current position
}

void bstTraversalRecursive(BStree bst, int pos) {
	if ((pos * 2 + 1 <= bst.size) && (pos * 2 <= bst.size) && (*(bst.is_free + pos) != 1) && (pos <= bst.size)) {
		bstTraversalRecursive(bst, pos * 2);    // Traverse the left subtree
		print_node(*(bst.tree_nodes + pos));    // Print the current node
		bstTraversalRecursive(bst, pos * 2 + 1);  // Traverse the right subtree
	}        
}
