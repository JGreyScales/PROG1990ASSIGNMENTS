#include "Utils.h"

//Write a function called SmallerOf(double, double) that replaces the contents
//of two double variables with the smaller of the two values.For example,
//SmallerOf(x, y) would reset both x and y to the smaller of the two.Please also
//prepare a set of unit tests written following the testing strategies(and tools)
//presented in this class or your Projects I course.Be sure to test(and include)
//all the edge cases you can think of to ensure your function works for all double
//variables.

// Jackson G - Prog71990 - Assignment 3 Question 1 - 2024-10-06


//Question 1: SmallerOf() function and tests
//o Specifications : 3.00 / 4.00 (The program works and produces the correct 
// results and displays them correctly and also meets most of the other 
// specifications or the following issues were noted : )
//�Test Case(s) are not verifying the proper outcome, possibly due to 
// misunderstood specification

int main(void) {
	double a = -2;
	double b = 5;

	smaller_of(&a, &b);

	return 0;
}