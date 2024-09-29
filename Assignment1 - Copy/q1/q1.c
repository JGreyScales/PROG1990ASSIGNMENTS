#define _CRT_SECURE_NO_WARNINGS
// write a program that takes a full name, outputs 4 lines like so
// Jackson Glover \n
// Jackson \n Glover \n
// print(Jackson) print(Glover)
// 
// Jackson G - prog71990 - assignment 3 - question 1 - 2024-09-29

#include <stdio.h>
#include "UserInput.h"

// if changed, must be modified inside UserInput.c
#define MAX_VALID_NAME_LENGTH		60
#define INVALID_ASSIGNMENT_ERROR	1

int main(void) {
	// Input
	char firstName[MAX_VALID_NAME_LENGTH];
	char lastName[MAX_VALID_NAME_LENGTH];

	printf("Please enter your first name:");
	// returns 1 on failure
	if (get_user_char_input(&firstName)) {
		return INVALID_ASSIGNMENT_ERROR; 
	}

	printf("Please enter your last name:");
	// returns 1 on failure
	if (get_user_char_input(&lastName)) {
		return INVALID_ASSIGNMENT_ERROR;
	}

	// Transform + Output
	printf("%s %s \n", firstName, lastName);
	printf("%s \n%s \n", firstName, lastName);
	printf("%s ", firstName);
	printf("%s", lastName);

	return 0;
}