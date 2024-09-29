#define _CRT_SECURE_NO_WARNINGS
// make a program that converts years to days & displays both days & years in 
// output
// 
// Jackson G - prog71990 - assignment 3 - question 2 - 2024-09-29
#include <stdio.h>
#include "UserInput.h"

#define DAYS_IN_YEAR				365

int main(void) {
	// intro
	int ageInYears = 0;

	printf("Please input your age in years, please round to single digit\n");

	// 0 for success
	// 1 for invalid assignment
	// 2 for out of range error

	// all error messages are handled inside function
	int returnStatus = get_int_from_user(&ageInYears);

	if (0 != returnStatus) {
		return returnStatus;
	}

	// Introduce the program
	printf("converting %i years to age in days...\n", ageInYears);

	// transform
	int ageInDays = ageInYears * DAYS_IN_YEAR;

	//output
	printf("Your age in days is:%i\n", ageInDays);
	printf("Your age in years is:%i", ageInYears);

	return 0;
}