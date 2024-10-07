#include "Utils.h"

// Implimentation of util functions
// Jackson G - Prog71990 - Assignment 3 Question 1 - 2024-10-06

void smaller_of(double* valueOne, double* valueTwo) {
	if (*valueOne <= *valueTwo) {
		*valueTwo = *valueOne;
	}
	else {
		*valueOne = *valueTwo;
	}
	return;
}