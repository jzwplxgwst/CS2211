// CS2211a 2023, Section 1
// Assignment 3
// James Wong
// 251297165
// jwong988
// Oct 20 2023

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
	char cont, neg;		// character used to continue running the program, and checks if the integer is negative
	bool check = false;	// boolean used to keep the loop running
	int count;		// counter for the number of digits
	int reversedNum;	// integer to hold the reversed form of the input
	int input;		// input set to a negative to loop 
	int holdInput, digit, holdCount, holdReversedNum;	// a temporary input and temporary digit

	// the 3D array of characters to store the 10 digits
	const char segements[10][3][3] = {
		{{' ','_',' '},{'|',' ','|'},{'|','_','|'}}, 
		{{' ',' ',' '},{' ','|',' '},{' ','|',' '}},
		{{' ','_',' '},{' ','_','|'},{'|','_',' '}},
		{{' ','_',' '},{' ','_','|'},{' ','_','|'}},
		{{' ',' ',' '},{'|','_','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_',' '},{' ','_','|'}},
		{{' ','_',' '},{'|','_',' '},{'|','_','|'}},
		{{' ','_',' '},{' ',' ','|'},{' ',' ','|'}},
		{{' ','_',' '},{'|','_','|'},{'|','_','|'}},
		{{' ','_',' '},{'|','_','|'},{' ','_','|'}}
	};

	while (!check) {
		count = 0;
		reversedNum = 0;
		input = -1;
		neg = false;
			
		// get the user's input
		printf("Input an integer: ");
		scanf("%d", &input);
		
		// check if the integer is negative	
		if (input < 0) {
			neg = true;
			input = abs(input);
		}

		holdInput = input;	// temporary hold the input

		// find the number of integers
		do { 
			holdInput/=10;	// divide the input by 10 each time 
			count++;	// increase count each time a digit is found
		} while (holdInput != 0);	// loop while the input is not 0
		
		// reverse the order iof the numbers to get left to right
		holdInput = input;

		while(holdInput != 0) {
			digit = holdInput%10;	// get the right digit
			reversedNum = reversedNum*10+digit;	// append the digit
			holdInput = holdInput/10;	// remove the right digit
		}
	
		holdCount = count;
		holdReversedNum = reversedNum;

		// add whitespace before the integer to show its negative
		if (neg) {
			printf("   ");
		}
		
		// displaying the 7 segement digits
		// displaying the top row of each digit
		while(holdCount>0) {
			digit = holdReversedNum%10;

			printf(" ");

			for (int i=0; i<3; i++) {
				printf("%c", segements[digit][0][i]);	// print each top row
			}
			
			holdReversedNum /= 10;	// divide the reversed number by 10 to get rid of the right number
			holdCount--;	// decrease counter
		}
		printf("\n");

		holdCount = count; 	// reset the counter
		holdReversedNum = reversedNum;	// reset the reversed number
		
		// add a '-' before the integer to show it is negative
		if (neg) {
			printf(" __");
		}

		// displaying the middle row of each digit
		while(holdCount>0) {
			digit = holdReversedNum%10;
			
			printf(" ");
			
			for (int i=0; i<3; i++) {
				printf("%c", segements[digit][1][i]);	// print each top row
			}
			holdReversedNum /= 10;	// divide the reversed number by 10 to get rid of the right number
			holdCount--;	// decrease counter
		}
		printf("\n");

		holdCount = count; 	// reset the counter
		holdReversedNum = reversedNum;	// reset the reversed number
 		
		// add whitespace before the integer to show its negative
		if (neg) {
			printf("   ");
		}

		// displaying the bottom row of each digit
		while(holdCount>0) {
			digit = holdReversedNum%10;

			printf(" ");
			for (int i=0; i<3; i++) {
				printf("%c", segements[digit][2][i]);	// print each bottom row
			}

			holdReversedNum /= 10;	// divide the reversed number by 10 to get rid of the right number
			holdCount--;
		}
		printf("\n");
			
		// check if the user wishes to continue
		do {
			printf("Do you wish to continue (Y/N)? ");
			scanf(" %c", &cont); // use & to get the address of the variable
		} while (cont != 'Y' && cont != 'N' && cont != 'y' && cont != 'n');

		if (cont == 'N' || cont == 'n') {
			check = true;
		}
	}
	return 0;
}
