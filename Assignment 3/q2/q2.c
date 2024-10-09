//Write a function that returns the sum(addition) of the largest and the smallest
//elements of an array of doubles.You may choose an appropriate name for your
//function.Please also prepare a set of unit tests written following the testing
//strategies(and tools) presented in this class or your Projects I course.Be
//sure to test(and include) all the edge cases you can think of to ensure your
//function works for all float variables

// Jackson G - Prog71990 - Assignment 3 Question 2 - 2024-10-06

#include "Utils.h"

int main(void) {

	double values[] = { 5, 5, 5, 5, 5, 6};

	// takes the total bytes contained in the array
	// divided by the length of a single item
	// this returns an unsigned int containing the number of elements
	int lengthOfArray = sizeof(values) / sizeof(values[0]);

	// sizeof data is lost when passing array, making me unable to deal
	// with variable lengths
	// thus length of array must be passed seperately
	sum_of_smallest_and_largest(values, lengthOfArray);
	return 0;
}