#define _CRT_SECURE_NO_WARNINGS

// make program to take 2 floats
// print sum, product, quotient
//
// Jackson G - prog71990 - assignment 3 - question 3 - 2024-09-29

#include <stdio.h>
#include "Userinput.h"
#include "Util.h"

#define INVALID_ASSIGNMENT_ERROR	1

int main(void) {
	float Number1 = 0.0f;
	float Number2 = 0.0f;

	printf("please input first number:");
	// returns 0 for success
	// returns 1 for assignment error
	if (get_float_from_user(&Number1)) {
		return INVALID_ASSIGNMENT_ERROR;
	}

	printf("please input the second number:");
	// returns 0 for success
	// returns 1 for assignment error
	if (get_float_from_user(&Number2)) {
		return INVALID_ASSIGNMENT_ERROR;
	}

	// transform + output
	output_math_operations(Number1, Number2);

	// output
	return 0;
}