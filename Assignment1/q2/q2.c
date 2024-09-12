#define _CRT_SECURE_NO_WARNINGS
// make a program that converts years to days & displays both days & years in 
// output
// 
// Jackson G - prog71990 - assignment 1 - question 2 - 2024-09-11

#include <stdio.h>

#define DAYS_IN_YEAR				365

int main(void) {
	// intro
	int ageInYears = 19;

	// Introduce the program
	printf("converting %i to age in days...\n", ageInYears);

	// transform
	int ageInDays = ageInYears * DAYS_IN_YEAR;

	//output
	printf("Your age in days is:%i\n", ageInDays);
	printf("Your age in years is:%i", ageInYears);

	return 0;
}