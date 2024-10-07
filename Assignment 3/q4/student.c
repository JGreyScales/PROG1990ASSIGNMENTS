#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include "student.h"

// Implementation of Student Struct
// Jackson G - Prog71990 - Assignment 3 - Question 4 - 2024-10-06


STUDENT create_student(int studentNumber, char firstName[NAME_MAX_SIZE], 
					  char middleName[NAME_MAX_SIZE],
					  char lastName[NAME_MAX_SIZE]) {
	NAME studentName;
	STUDENT student;

	strncpy(studentName.firstName, firstName, NAME_MAX_SIZE);
	strncpy(studentName.middleName, middleName, NAME_MAX_SIZE);
	strncpy(studentName.lastName, lastName, NAME_MAX_SIZE);

	student.studentNumber = studentNumber;
	student.studentName = studentName;

	return student;
}


void print_student(STUDENT student) {
	printf("%d - %s, %s", student.studentNumber,
		student.studentName.firstName, student.studentName.lastName);

	// a string must be defined, but 'empty' strings are only containing 
	// the terminator
	if (student.studentName.middleName[0] != '\0') {
		printf(" %c.", student.studentName.middleName[0]);
	}

	printf("\n");
}

void print_students(STUDENT studentArray[], int count) {
	for (int i = 0; i < count; i++) {
		print_student(studentArray[i]);
	}
}