// cs2211
// // assignment 4
// // James Wong
// // 251297165
// // jwong988
// // Nov 13 2023

#include "data.h"

typedef struct {
	Node *tree_nodes; 
	unsigned char *is_free; 
	int size;
} BStree;

BStree bstree_ini(int size);

void bstree_insert(BStree bst, Key key, int data);

void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void bstree_free(BStree bst);
