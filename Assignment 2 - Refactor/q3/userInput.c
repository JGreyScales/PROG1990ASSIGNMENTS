#define _CRT_SECURE_NO_WARNINGS

// Jackson G - prog71990 - assignment 2 refactor - question 3 - 2024-10-16
// Implementation of user facing functions

#include <stdio.h>
#include "UserInput.h"

enum state {break_loop = -1, success = 0, invalid_assignment = 1,
			out_of_bounds_error = 2 };

int get_int_from_user(int* assignmentVar) {
	enum state codeStatus = 0;
	// Take user input
	if (1 != scanf("%i", assignmentVar)) {
		printf("Invalid Assignment, ensure is of type int\n");
		printf("Value must be greater than zero");
		codeStatus = 1;
		return codeStatus;
	}

	if (-1 == *assignmentVar) {
		codeStatus = -1;
		return codeStatus;
	}

	if (0 >= *assignmentVar) {
		printf("Value must be greater than 0");
		codeStatus = 2;
		return codeStatus;
	}

	return codeStatus;
}
