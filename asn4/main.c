// cs2211
// // assignmetn 4
// James Wong
// 251297165
// jwong988
// Nov 13 2023

#include <stdio.h>
#include "bst.h"
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int num1, num2;
	char str[25];
	bool check = true, check2;
	char answer, answer2;

	// test case 1
	BStree bst;
	bst = bstree_ini(600);
	printf("Test case 1: Sample test given by instructor\n");
	bstree_insert(bst, key_construct("Oxford Street", 70), 2500);
	bstree_insert(bst, key_construct("3 Valleys Place", 8), 2000);
	bstree_insert(bst, key_construct("Western Road", 101), 2500);
	bstree_insert(bst, key_construct("3rd Street", 74), 3000);
	bstree_insert(bst, key_construct("4 Oaks Crescent", 4), 2100);
	bstree_insert(bst, key_construct("Abbott Street", 10), 2300);
	bstree_insert(bst, key_construct("1st Street", 100), 1000);
	bstree_insert(bst, key_construct("Beech Drive", 204), 1800);
	bstree_insert(bst, key_construct("Beechbank Crescent", 36), 2400);
	bstree_insert(bst, key_construct("Beechmount Crescent", 36), 2500);
	bstree_insert(bst, key_construct("Oxford Street", 46), 2600);
	bstree_traversal(bst);
	bstree_free(bst);

	// test case 2
	BStree bst2;
	bst2 = bstree_ini(600);
	printf("Test case 2: Different order of sample test given by instructor\n");
	bstree_insert(bst2, key_construct("Oxford Street", 70), 2500);
	bstree_insert(bst2, key_construct("Beechbank Crescent", 36), 2400);
	bstree_insert(bst2, key_construct("Beechmount Crescent", 36), 2500);
	bstree_insert(bst2, key_construct("Western Road", 101), 2500);
	bstree_insert(bst2, key_construct("Oxford Street", 46), 2600);
	bstree_insert(bst2, key_construct("3rd Street", 74), 3000);
	bstree_insert(bst2, key_construct("3 Valleys Place", 8), 2000);
	bstree_insert(bst2, key_construct("1st Street", 100), 1000);
	bstree_insert(bst2, key_construct("Abbott Street", 10), 2300);
	bstree_insert(bst2, key_construct("4 Oaks Crescent", 4), 2100);
	bstree_insert(bst2, key_construct("Beech Drive", 204), 1800);
	bstree_traversal(bst2);
	bstree_free(bst2);

	// test case 3
	BStree bst3;
	bst3 = bstree_ini(600);
	printf("Test case 3: Insert a binary search tree\n");
	while (check) {
		check2 = true;
		printf("Enter the binary number name: ");
		scanf("%d ", &num1);
		fgets(str, sizeof(str), stdin);

		printf("Enter the binary search tree number: ");
		scanf("%d", &num2);
		size_t len = strlen(str);
	
		if(len>0 && str[len - 1] == '\n') {
			str[len-1] = '\0';
		}
		bstree_insert(bst3, key_construct(str, num1), num2);	// insert the binary tree
		
		// exit loop
		while (check2) {
			printf("Do you wish to add more? (Y or N) ");
			scanf(" %c", &answer);

			if (answer == 'Y') {
				check2 = false;
			} else if (answer == 'N') {
				bstree_traversal(bst3);
				bstree_free(bst3);
				check = false;
				check2 = false;
			} else {
				check2 = true;

			}
		}
	}

	// test case 4
	BStree bst4;
	bst4 = bstree_ini(600);
	printf("Test case 4: Reading from stdin or redirect from a file\n");
	if (argc != 2) {
		fprintf(stderr, "Usage: %2 <input_file>\n", argv[0]);
		return 1;
	}

	FILE *input_file = fopen(argv[1], "r");
	if (input_file == NULL) {
		printf("Error opening file");
		return 1;
	}

	char line[81];
	while (fscanf(input_file, "%d%d%80[^\n]", &num1, &num2, str) == 3) {
		bstree_insert(bst, key_construct(str, num2), num1);
	}

	fclose(input_file);

	bstree_traversal(bst4);
	bstree_free(bst4);
}
