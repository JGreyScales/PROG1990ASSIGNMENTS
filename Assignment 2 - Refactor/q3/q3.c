#define _CRT_SECURE_NO_WARNINGS

//Write a program that asks the user to enter some number of days and then
//converts that value to weeks and days.For example, it would convert 18 days
//to 2 weeks, 4 days.Display results in the following format :
//18 days is 2 weeks, 4 days.
//Use a do...while loop construct to allow the user to repeatedly enter day
//values; terminate the loop when the user enters a non - positive value, such as
//0 or -20.


// Jackson G - prog71990 - assignment 2 refactor - question 3 - 2024-10-16

#include <stdio.h>
#include "userInput.h"
#include "weekMath.h"

int main(void) {
	int looping = 1;

	do {
		// input
		int userInputDays = 0;
		int weeks = 0;

		printf("Please input the number of days you want to convert\n");
		printf("Enter -1 to stop the loop:\n ");

		// returns 0 for success
		// returns -1 for break loop
		int returnStatus = get_int_from_user(&userInputDays);
		if (0 < returnStatus) {
			return returnStatus;
		}
		if (-1 == returnStatus) {
			looping = 0;
		}
		else {
			// process
			int remainder = convert_to_weeks_return_days(userInputDays, &weeks);

			// output
			printf("%d to weeks is: %d weeks and %d days\n\n", userInputDays,
				weeks, remainder);


		}
	} while (looping);
	return 0;

}
