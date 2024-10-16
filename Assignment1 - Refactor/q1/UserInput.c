#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include "UserInput.h"

// Jackson G - prog71990 - assignment 3 - question 1 - 2024-09-29
// Implementation of user facing functions (User Input)

#define INVALID_ASSIGNMENT_ERROR	1
#define MAX_VALID_NAME_LENGTH		60

int get_user_char_input(char* assignmentVar) {
	// Take user input (the name of the user)
	if (1 != scanf("%60s", assignmentVar)) {
		printf("Invalid Assignment, ensure that type is string & length is ");
		printf("less than %i", MAX_VALID_NAME_LENGTH);
		return INVALID_ASSIGNMENT_ERROR;
	}
	return 0;
}