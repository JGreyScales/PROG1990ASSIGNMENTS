#define _CRT_SECURE_NO_WARNINGS

//Write a program that asks the user to enter some number of days and then
//converts that value to weeks and days.For example, it would convert 18 days
//to 2 weeks, 4 days.Display results in the following format :
//18 days is 2 weeks, 4 days.
//Use a do...while loop construct to allow the user to repeatedly enter day
//values; terminate the loop when the user enters a non - positive value, such as
//0 or -20.


// Jackson G - prog71990 - assignment 2 - question 3 - 2024-09-22

#include <stdio.h>

#define INVALID_ASSIGNMENT 1
#define OUT_OF_RANGE_ERROR 2

#define LENGTH_OF_WEEK	   7

static int convert_to_weeks(int days) {
	int weeks = 0;

	// loop until days is less than a week
	while( days >= LENGTH_OF_WEEK){
		weeks++;
		days -= LENGTH_OF_WEEK;
	}

	return weeks;
}

static int calulcate_remainder(int days) {
	return days % LENGTH_OF_WEEK;
}

int main(void) {
	int looping = 1;

	// input
	int userInputDays = 0;


	printf("Please input the number of days you want to convert\n");
	printf("Enter -1 to stop the loop:\n ");

	if (1 != scanf("%d", &userInputDays)) {
		printf("Invalid assignment, ensure is of type int");
		return INVALID_ASSIGNMENT;
	}
	// User enters -1 to break the loop
	else if (-1 == userInputDays) {
		looping = 0;
	}
	// only positive integers are allowed
	else if (0 >= userInputDays) {
		printf("Out of range, please ensure the value is greater than zero");
		return OUT_OF_RANGE_ERROR;
	}
	else {
		// output
		printf("%d to weeks is: %d weeks and %d days\n\n",

			// process
			userInputDays, convert_to_weeks(userInputDays),
			calulcate_remainder(userInputDays));
	}
	return 0;

}
