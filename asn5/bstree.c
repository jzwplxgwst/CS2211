// CS2211a 2023, Section 1
// // Assignment 5
// // James Wong
// // 251297165
// // jwong988
// // Nov 23 2023

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

// Input: void
// Output: a binary search tree
// Effect: initialize an empty BST
BStree bstree_ini(void) {
	BStree bst = (BStree)malloc(sizeof(BStree_node*));

	if (bst != NULL) {
		*bst = NULL;	// set the value to null
	}

	return bst;
}

// Input: a key and a data
// Output: a new node
// Effect: create a new bst node
BStree_node* new_node(Key key, Data data) {
	BStree_node* newNode = (BStree_node*)malloc(sizeof(BStree_node));

	if (newNode != NULL) {
		newNode->key = key;
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}

// Input: A root node, a key and a data
// Output: a root
// Effect: recursive helper function for insertion
BStree_node* bstreeInsert_recursive(BStree_node* root, Key key, Data data) {
	if (root == NULL) {
		return new_node(key, data);	// if the current not id null, create a new node
	} 

	int compare = key_comp(key, root->key);

	if (compare < 0) {
		root->left = bstreeInsert_recursive(root->left, key, data);	// if key is smaller, insert into the left subtree
	} else if (compare > 0) {
		root->right = bstreeInsert_recursive(root->right, key, data);	// if the key is larger, insert into the right subtree
	}
		
	return root;	// if key is equal return the root
}

// Input: a binary search tree, a key and a data
// // Output: Nothing
// // Effect: insert a key value pair into the bst
void bstree_insert(BStree bst, Key key, Data data) {
	*bst = bstreeInsert_recursive(*bst, key, data);
}

// Input: a root node, a key
// // Output: return a root
// // Effect: recursive helper function for search
Data bstSearch_recursive(BStree_node* root, Key key) {
	if (root == NULL) {
		return NULL;
	}
	
	int compare = key_comp(key, root->key);
	if (compare < 0) {
		return bstSearch_recursive(root->left, key);
	} else if (compare > 0) {
		return bstSearch_recursive(root->right, key);
	} else {
		return root->data;
	}
}

// Input: a binary search tree and a key
// Output: the searchfor a bst
// Effect: search for a key in the BST
Data bstree_search(BStree bst, Key key) {
	return bstSearch_recursive(*bst, key);
}

// Input: a binary search tree root node
// // Output: nothing
// // Effect: recursive helper function for inorder traversal
void bstTraverse_recursive(BStree_node *root) {
	if (root != NULL) {
		bstTraverse_recursive(root->left);
		key_print1(root->key);
		data_print(root->data);
		bstTraverse_recursive(root->right);
	}
}

// Input: a binary search tree
// Output: Nothing
// Effect: perform an inorder traversal of the BST
void bstree_traverse(BStree bst) {
	bstTraverse_recursive(*bst);
	printf("\n");
}

// Input: a binary search tree root node
// Output: Nothing
// Effect: recursive helper function for freeing up memory
void bstFree_recursive(BStree_node* root) {
	if (root != NULL) {
		bstFree_recursive(root->left);
		bstFree_recursive(root->right);
		
		// free memory allocated from bst
		key_free(root->key);
		data_free(root->data);
		free(root);
	}
}

// Input: a binary search tree
// Output: nothing
// Effect: free all dynamically allocated memory of BST
void bstree_free(BStree bst) {
	bstFree_recursive(*bst);
	free(bst);
}




