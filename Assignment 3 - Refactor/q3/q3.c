//Write a function that sets each element in an array to the product of the
//corresponding elements in two other arrays.For example, if array 1 has the
//values{ 2, 4, 5, 8 } and array 2 has the values{ 1, 0, 4, 6 }, the function
//1
//should assign array 3 the values{ 2, 0, 20, 48 } . The name of this function
//should be named MultiplyTwoArraysIntoThird and the arrays should be sent as
//function parameters.Please also prepare a set of unit tests written following
//the testing strategies(and tools) presented in this class or your Projects I
//course.Be sure to include all the tests you performed to demonstrate that
//this function works as specified.

// Jackson G - Prog71990 - Assignment 3 Question 3 - 2024-10-06

#include "Utils.h"

int main(void) {

	int arr[] = { 2, 4, 5 ,8 };
	int arr2[] = { 1, 0, 4, 6 };
	int returnArry[] = { 0, 0, 0 ,0};

	int length = sizeof(arr) / sizeof(arr[0]);

	// returnArray will be overridden with values from function
	multiply_two_arrays_into_third(arr, arr2, length, returnArry);

	return 0;
}