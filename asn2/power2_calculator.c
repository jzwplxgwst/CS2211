#include <stdio.h>
#include <stdbool.h>	// Include the header for the bollean data type

/* declaring the calculation function */
unsigned long long power2_calculator(unsigned int num);

int main() {
	bool check = false;	// boolean to keep the loop running
	unsigned int num;	// user's input (exponent)
	unsigned long long result;	// the product 
	
	/* Loop until 0 is inputed */
	while (!check){
		
		printf("Enter the exponent value: ");
		scanf(" %u", &num);

		if (num == 0) {		// 2 to the power of 0 is always 1
			printf("2 to the power of 0 is 1.\n");	
			check = true; // set check to true to exit the program
			break; 
		}
		
		result = power2_calculator(num);	// power calculation
		printf("2 to the power of %u is %u.\n", num, result);
	}	
	return 0;
}

/* recursive function to calculate the power of two */
unsigned long long power2_calculator(unsigned int num) {
	unsigned long long temp;	// the calculated value
	// catch 0 when the program is recurring
	if (num == 0) {	
		return 1;	// return 1 to force the program to access the odd formula
	} else {
		if (num%2==0) {		// if exponent is even
			temp = power2_calculator(num/2);	// even calculation formula
			return temp*temp;
		} else {		// if exponent is odd
			temp = power2_calculator((num-1)/2);	// odd calculation formula
			return temp*temp*2;
		}
	}
}
