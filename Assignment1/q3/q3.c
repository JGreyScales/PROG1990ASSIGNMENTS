#define _CRT_SECURE_NO_WARNINGS
// make program to take 2 floats
// print sum, product, quotient


// Jackson G - prog71990 - assignment 1 - question 3 - 2024-09-11
#include <stdio.h>

#define INVALID_ASSIGNMENT	1

int main(void) {
	float Number1;
	float Number2;

	// intro
	printf("please input first number:");

	// input 
	if (1 != scanf("%f", &Number1)) {
		printf("Invalid input, please ensure that input is a valid float type");
		return INVALID_ASSIGNMENT;
	}

	printf("please input the second number:");

	if (1 != scanf("%f", &Number2)) {
		printf("Invalid input, please ensure that input is a valid float type");
		return INVALID_ASSIGNMENT;
	}

	//transform + output
	printf("The sum is: %f\n", Number1 + Number2);
	printf("The product is: %f\n", Number1 * Number2);

	// conditionals placed here to keep code flow constant & easy to follow.
	if (0 == Number2) { printf("The quotient is: INVALID, DIVISION BY ZERO ERROR");}
	else { printf("The quotient is: %f", Number1 / Number2); }



	// output
	return 0;
}