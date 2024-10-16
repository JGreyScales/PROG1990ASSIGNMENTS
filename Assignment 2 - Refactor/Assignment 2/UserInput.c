#define _CRT_SECURE_NO_WARNINGS

// Jackson G - prog71990 - assignment 2 refactor - question 1 - 2024-10-14
// Implementation of user facing functions

#include <stdio.h>
#include "UserInput.h"

#define MINIMUM_VALID_AGE			0
#define INVALID_ASSIGNMENT_ERROR	1

int get_int_from_user(int* assignmentVar) {
	// Take user input
	if (1 != scanf("%i", assignmentVar)) {
		printf("Invalid Assignment, ensure is of type int\n");
		printf("Value must be greater than zero");
		return INVALID_ASSIGNMENT_ERROR;
	}

	return 0;
}
