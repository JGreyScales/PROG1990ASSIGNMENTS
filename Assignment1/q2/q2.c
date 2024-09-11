#define _CRT_SECURE_NO_WARNINGS
// make a program that converts years to days & displays both days & years in 
// output
// Jackson G - prog71990 - assignment 1 - question 2 - 2024-09-11

#include <stdio.h>

#define INVALID_ASSIGNMENT_ERROR	1
#define INVALID_DOMAIN				2
#define DAYS_IN_YEAR				365

int main(void) {
	// intro
	int ageInYears;

	printf("Please input your age in years:");

	int assignedItems = scanf("%i", &ageInYears);
	if (1 != assignedItems) {
		printf("Invalid assignment, ensure that type is of int");
		return INVALID_ASSIGNMENT_ERROR;
	}
	if (0 >= ageInYears) {
		printf("Invalid domain, please ensure that age in years is greater ");
		printf("then or equal to 0");
		return INVALID_DOMAIN;
	}



	// transform
	int ageInDays = ageInYears * DAYS_IN_YEAR;


	//output
	printf("Your age in days is:%i\nYour age in years is:%i", ageInDays, ageInYears);

	return 0;
}