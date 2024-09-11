#define _CRT_SECURE_NO_WARNINGS
// write a program that takes a full name, outputs 4 lines like so
// Jackson Glover \n
// Jackson \n Glover \n
// print(Jackson) print(Glover)
// 
// Jackson G - prog71990 - assignment 1 - question 1 - 2024-09-11

#include <stdio.h>

#define INVALID_ASSIGNMENT	1

int main(void) {
	// Input
	char firstName[250];
	char lastName[250];

	// Introduce the program
	printf("Please enter your first name:");

	// Take user input (the name of the user)
	if (1 != scanf("%s", firstName)) {
		printf("Invalid Assignment, ensure that type is string & length is less than 250");
		return INVALID_ASSIGNMENT;
	}

	printf("Please enter your last name:");
	if (1 != scanf("%s", lastName)) {
		printf("Invalid Assignment, ensure that type is string & length is less than 500");
		return INVALID_ASSIGNMENT;
	}


	// Transform + Output
	printf("%s %s \n", firstName, lastName);
	printf("%s \n%s \n", firstName, lastName);
	printf("%s ", firstName);
	printf("%s", lastName);

	return 0;
}