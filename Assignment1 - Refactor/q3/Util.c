#define _CRT_NO_SECURE_WARNINGS

// Jackson G - prog71990 - assignment 3 - question 3 - 2024-09-29
// Implementation of user facing functions

#include <stdio.h>
#include "UserInput.h"

#define MINIMUM_VALID_AGE			0
#define INVALID_ASSIGNMENT_ERROR	1

float output_math_operations(float Number1, float Number2){
	printf("The sum is: %f\n", Number1 + Number2);
	printf("The product is: %f\n", Number1 * Number2);

	// conditionals placed here to keep code flow constant & easy to follow.
	if (0 == Number2) {
		printf("The quotient is: INVALID, DIVISION BY ZERO ERROR");
	}
	else { printf("The quotient is: %f", Number1 / Number2); }
}