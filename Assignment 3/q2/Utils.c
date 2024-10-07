#include "Utils.h"

// Implimentation of Utils
// Jackson G - Prog71990 - Assignment 3 Question 2 - 2024-10-06

double sum_of_smallest_and_largest(double doubleArray[], int arrLength) {
	double smallestValue = doubleArray[0];
	double largestValue = doubleArray[0];
	for (int i = 0; i < arrLength; i++) {
		if (doubleArray[i] > largestValue) {
			largestValue = doubleArray[i];
		}
		else if (doubleArray[i] < smallestValue) {
			smallestValue = doubleArray[i];
		}
	}

	return smallestValue + largestValue;
}