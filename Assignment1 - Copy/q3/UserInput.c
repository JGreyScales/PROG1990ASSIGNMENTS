#define _CRT_NO_SECURE_WARNINGS

// Jackson G - prog71990 - assignment 3 - question 3 - 2024-09-29
// Implementation of user facing functions

#include <stdio.h>
#include "UserInput.h"

#define MINIMUM_VALID_AGE			0
#define INVALID_ASSIGNMENT_ERROR	1

void get_float_from_user(float* assignmentVar) {
	// Take user input (the age of the user)
	if (1 != scanf("%i", assignmentVar)) {
		printf("Invalid Assignment, ensure is of type float\n");
		return INVALID_ASSIGNMENT_ERROR;
	}
	return 0;
}