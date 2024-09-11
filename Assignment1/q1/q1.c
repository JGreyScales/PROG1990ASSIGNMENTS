#define _CRT_SECURE_NO_WARNINGS
// write a program that takes a full name, outputs 4 lines like so
// Jackson Glover \n
// Jackson \n Glover \n
// print(Jackson) print(Glover)
// 
// Jackson G - prog71990 - assignment 1 - question 1 - 2024-09-11

#include <stdio.h>

#define INVALID_ASSIGNMENT_ERROR	1
#define BUFFER_OVERFLOW_ERROR		2
// if changed, must be modified inside line 25, 31 of scanf functions
#define MAX_VALID_NAME_LENGTH		250

int main(void) {
	// Input
	char firstName[MAX_VALID_NAME_LENGTH];
	char lastName[MAX_VALID_NAME_LENGTH];

	// Introduce the program
	printf("Please enter your first name:");

	// Take user input (the name of the user)
	if (1 != scanf("%250s", firstName)) {
		printf("Invalid Assignment, ensure that type is string & length is less than %i", MAX_VALID_NAME_LENGTH);
		return INVALID_ASSIGNMENT_ERROR;
	}

	printf("Please enter your last name:");
	if (1 != scanf("%250s", lastName)) {
		printf("Invalid Assignment, ensure that type is string & length is less than %i", MAX_VALID_NAME_LENGTH);
		return INVALID_ASSIGNMENT_ERROR;
	}


	// Transform + Output
	printf("%s %s \n", firstName, lastName);
	printf("%s \n%s \n", firstName, lastName);
	printf("%s ", firstName);
	printf("%s", lastName);

	return 0;
}