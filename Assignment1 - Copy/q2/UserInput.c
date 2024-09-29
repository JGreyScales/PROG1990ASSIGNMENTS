#define _CRT_SECURE_NO_WARNINGS

// Jackson G - prog71990 - assignment 3 - question 2 - 2024-09-29
// Implementation of user facing functions

#include <stdio.h>
#include "UserInput.h"

#define MINIMUM_VALID_AGE			0
#define INVALID_ASSIGNMENT_ERROR	1
#define INVALID_RANGE_ERROR			2

int get_int_from_user(int* assignmentVar) {
	// Take user input (the age of the user)
	if (1 != scanf("%i", assignmentVar)) {
		printf("Invalid Assignment, ensure is of type int\n");
		printf("Value must be greater than zero");
		return INVALID_ASSIGNMENT_ERROR;
	}
	if (0 >= *assignmentVar) {
		printf("Invalid range, must be of type int and greater than 0");
		return INVALID_RANGE_ERROR;
	}
	return 0;
}
