#define _CRT_SECURE_NO_WARNINGS

// Jackson G - prog71990 - assignment 2 refactor - question 3 - 2024-10-16
// Implementation for math functions regarding weeks

#include "weekMath.h"

#define LENGTH_OF_WEEK	   7

int convert_to_weeks_return_days(int days, int* weeks) {

	// loop until days is less than a week
	while (days >= LENGTH_OF_WEEK) {
		(*weeks)++;
		days -= LENGTH_OF_WEEK;
	}

	return days;
}