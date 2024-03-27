// cs2211
// // assignment 4
// // James Wong
// // 251297165
// // jwong988
// // Nov 13 2023

#include <stdio.h>

// calculate the factorial of a number    
long long factorial(int n) {
	if (n == 0) {
		return 1;	// return 1
	} else { 
	     	return n * factorial(n - 1);	// return the factorial
	}
}
// calculate the mathematical constant of e
double euler(double epsilon) {
	double eulerValue = 1.0;	// set euler value
	
	for (int i=1; 1.0/factorial(i) >= epsilon; i++) {	// for loop to increase the euler value
		eulerValue += 1.0/factorial(i);
	}

	return eulerValue;	// return the euler value
}

// main program
int main() {
	double input;	// user input

	printf("Enter a small number e: ");	// small number to convert
	scanf("%lf", &input);

	printf("\nThe Mathematical constant e: %.15lf\n", euler(input));	// print statement

	return 0;
}

