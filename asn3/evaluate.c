// CS2211a 2023, Section 1
// Assignment 3
// James Wong
// 251297165
// jwong988
// Oct 20 2023

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

// get the operator
char get_op() {
	char op = ' ';
	while(op == ' ') {
		scanf("%c", &op);
	}
	return op; 	// return the next operator
}

// get the number
float get_num() {
	float num; 
	scanf("%f", &num);
	return num; 	// return the next number
}

// the value of the current sub simple arithmetic
float sub_sim_exp(float sub_exp) {
	char next_op = get_op();	// get the next op with get_op()

	if (next_op == '\n') {
		return sub_exp;
	} else if (next_op == '+' || next_op == '-') {
		float next_num = get_num();
		if (next_op == '+') {	// next_op == '+'
			return sub_sim_exp(sub_exp + next_num);

		} else {	// next_op == '-'
			return sub_sim_exp(sub_exp - next_num);
		}
	} else {
		printf("Invaid operator detected.\n");
		exit(EXIT_FAILURE);
	}
}

// returns the value of the simple arithmetic expression
float sim_exp(void) {
	float num = get_num();
	return sub_sim_exp(num);
}

int main() {
	char cont;	// character to hold the Y or N
	bool check = false;	// check is false to loop the program

	while(!check) {
		printf("Enter a simple arithmetic expression: ");	// user input
		float value = sim_exp();
		printf("The answer is: %g\n", value);

		do {
			printf("Do you wish to continue (Y/N)? ");
			scanf(" %c", &cont);
		} while (cont != 'Y' && cont != 'N' && cont != 'n' && cont != 'y');

		if (cont == 'N' || cont == 'n') {
			check = true;	// set check to true to end loop
		}
	}
	return 0;
}
