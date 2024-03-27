#include <stdio.h>
#include <stdbool.h>	// Include the header for the boolean data type

/* function declaration */
char celiFah();		// Celsius to Fahrenheit function
char centInc();		// Centimetre to Inch function
char kiloMile();	// Kilometre to Mile function
char galLiter();	// Gallon to Liter function

int main() {
	int convert;
	bool check = false;
	/* Loop until the user quits */
	while (!check) {
		// display the options for the user 
		printf("____________________________\n");
		printf("Quit: 0\n");
		printf("Celsius and Fahrenheit: 1\n");
		printf("Centimetre and Inch: 2\n");
		printf("Kilometer and Mile: 3\n");
		printf("Gallon and Liter: 4\n");
		printf("Enter a number 0-4 for: ");
		scanf(" %d", &convert);

		// Check the user's input and perform the selected case
		switch(convert) {
			case 1:
				celiFah();	// Call the Celsius to Fahrenheit conversion function
				break;
			case 2:
				centInc();	// Call the Centimetre to Inch conversion function
				break;
			case 3:
				kiloMile();	// Call the Kilometre to Mile conversion function
				break;
			case 4:
				galLiter();	// Call the Gallon to Liter conversion function
				break;
			case 0:
				check = true;	// Set check to true to end the loop
				break;
		}
	}
	return 0;
}
/**
 * Name: celiFah
 * Celsius to Fahrenheit and Fahrenheit to Celsius conversion function
 */
char celiFah () {
	char direction;		// user's character input
	bool check = false;
	float convertedValue, value;	// value is the user's intial value and convertedValue is the calculated value

	/* Loop until either case C or F is completed */
	while (!check) {
		// display a list of option for the user
		printf("Celcius to Fahrenheit: C\n");
		printf("Fahrenheit to Celcius: F\n");
		printf("Choose the direction of the conversion by typing in C or F: ");
		scanf(" %c", &direction);
			
		// check the user's chosen conversion direction
		switch (direction) {
			case 'C':
				printf("Enter the Celsius value: ");
				scanf(" %f", &value);
				convertedValue = (value*(1.8)+32);	// Celsius to Fahrenheit formula
				
				printf(" %.2f in Celsius is %.2f in Fahrenheit.\n", value, convertedValue);
				check = true;	// set check to true to exit the loop
				break;
					
			case 'F':
				printf("Enter the Fahrenheit value: ");
				scanf(" %f", &value);
				convertedValue = (value-32)*(5.0/9.0);	// Fahrenheit to Celsius formula
				
				printf("%.2f in Fahrenheit is %.2f in Celsius.\n", value, convertedValue);
				check = true;	// set check to true to exit the loop
				break;
					
		}
	}
}
/**
 * Name: centInc
 * Centimetre to Inch and Inch to Centimetre conversion function
 */
char centInc (){
	char direction;		// user's character input
	bool check = false;
	float convertedValue, value;	// value is the user's intial value and convertedValue is the calculated value

	/* Loop until either case C or I is completed */
	while (!check) {
		// display a list of option for the user
		printf("Centimetre to Inch: C\n");
		printf("Inch to Centimetre: I\n");
		printf("Choose the direction of the conversion by typing in C or I: ");
		scanf(" %c", &direction);

		// check the user's chosen conversion direction
		switch (direction) {
			case 'C':
				printf("Enter the Centimetre value: ");
				scanf(" %f", &value);
				convertedValue = value/2.54;	// Centimetre to Inch formula

				printf("%.2f in Centimetres is %.2f in Inches.\n", value, convertedValue);
				check = true;	// set check true to exit the loop
				break;
			case 'I':
				printf("Enter the Inch value: ");
				scanf(" %f", &value);
				convertedValue = value*2.54;	// Inch to Centimetre formula

				printf("%.2f in Inches is %.2f in Centimetres.\n", value, convertedValue);
				check = true;	// set check true to exit the loop
				break;	
		}
	}

}
/**
 * Name: kiloMile
 * Kilometre to Mile and Mile to Kilometre conversion formula
 */
char kiloMile (){	
	char direction;		// user's character input
	bool check = false;
	float convertedValue, value;	// value is the user's intial value and convertedValue is the calculated value

	/* Loop until either case K or M is completed */
	while(!check) {
		// Display a list of options for the user
		printf("Kilometer to Mile: K\n");
		printf("Mile to Kilometer: M\n");
		printf("Choose the direction of the conversion by typing in K or M: ");
		scanf(" %c", &direction);

		// check the user's chosen conversion direction
		switch (direction) {
			case 'K':
				printf("Enter the Kilometer value: ");
				scanf(" %f", &value);
				convertedValue = value/1.609;	// Kilometre to Mile formula

				printf("%.2f in Kilometers is %.2f in Miles.\n", value, convertedValue);
				check = true;	// set check to true to exit the loop
				break;
			case 'M':
				printf("Enter the Mile value: ");
				scanf(" %f", &value);
				convertedValue = value*1.609;	// Mile to Kilometre formula

				printf("%.2f in Miles is %.2f in Kilometers.\n", value, convertedValue);
				check = true;	// set check true to exit the loop
				break;
		}
	}
}
/*
 * Name: galLiter
 * Gallon to Liter and Liter to Gallon conversion formula
 */
char galLiter () {
	char direction;		// user's character input
	bool check = false;
	float convertedValue, value;	// value is the user's intial value and convertedValue is the calculated value

	/* Loop until either case G or L is completed */
	while(!check) {
		// Display a set of options for the user
		printf("Gallon to Liter: G\n");
		printf("Liter to Gallon: L\n");
		printf("Choose the direction of the conversion by typing in G or L: ");
		scanf(" %c", &direction);

		// check the user's chosen conversion direction
		switch (direction) {
			case 'G':
				printf("Enter the Gallon value: ");
				scanf(" %f", &value);
				convertedValue = value*3.785;	// Gallon to Liter formula

				printf("%.2f in Gallons is %.2f in Liters\n", value, convertedValue);
				check = true;	// set check true to exit the loop
				break;
			case 'L':
				printf("Enter the Liter value: ");
				scanf(" %f", &value);
				convertedValue = value/3.785;	// Liter to Gallon formula

				printf("%.2f in Liters is %.2f in Gallons.\n", value, convertedValue);
				check = true;	// set check true to exit the loop
				break;
		}
	}
}


