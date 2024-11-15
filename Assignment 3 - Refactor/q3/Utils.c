#include "Utils.h"

// Implentation of Utils
// Jackson G - Prog71990 - Assignment 3 Question 3 - 2024-10-06

// assumes all arrays are of equal length
int multiply_two_arrays_into_third(int array1[], int array2[], int length, int returnArray[]) {
	for (int i = 0; i < length; i++) {
		returnArray[i] = array1[i] * array2[i];
	}
}