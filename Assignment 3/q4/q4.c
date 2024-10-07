//First, write a component(a pair of.c and .h files) that defines a structure
//template with two member attributes according to the following criteria :
//• the first member is a student number as a single fixed length numeric field
//with a maximum length of 10 digits.
//• the second member is a structure with three members according to the
//following criteria :
//– first member is “first name”
//– second member is “middle name”
//– third member is “last name”
//Next, write and test a program that creates and initializes an array of 4 of
//these structures(Please make up pretend names / numbers for your 4 students
//	- be sure to have at least 2 students with middle names(and the full middle
//		name must be entered) and at least 1 without any middle name.
//	Finally, write a single function that accepts an array of these structures as a
//	parameter and prints the array data in the following format :
//2001041234 – LastName, FirstName MiddleInitial.
//and then use this function in your program to display your student records.
//Note that only the initial of the middle name should be printed, followed by
//a period.Any of your students who lack a middle name will end the output
//line at the end of the first name.
//For this question, Q4, it is not necessary to follow our unit testing procedures
//or submit your set of unit tests.Of course, testing your program to ensure
//that it works according to specification is encouraged!

#include "student.h"

// Jackson G - Prog71990 - Assignment 3 Question 4 - 2024-10-06


int main(void) {

	STUDENT x1 = create_student(1358329581, "ExampleFirst", "ExampleMiddle", "ExampleLast");
	STUDENT x2 = create_student(1493850039, "Josh", "Middleton", "Taylor");
	STUDENT x3 = create_student(1950285749, "Isaac", "", "Placen");
	STUDENT x4 = create_student(1945274921, "Yusif", "", "Appleton");

	STUDENT studentArray[] = { x1, x2, x3, x4 };
	int length = sizeof(studentArray) / sizeof(studentArray[0]);
	print_students(studentArray, length);

	return 0;
}