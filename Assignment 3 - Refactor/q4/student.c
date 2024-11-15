#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

// Implementation of Student Struct
// Jackson G - Prog71990 - Assignment 3 - Question 4 - 2024-10-06


PSTUDENT create_student(PSTUDENT* list, int studentNumber, char firstName[NAME_MAX_SIZE], 
					  char middleName[NAME_MAX_SIZE],
					  char lastName[NAME_MAX_SIZE]) {


	PNAME studentName = (PNAME)malloc(sizeof(NAME));
	PSTUDENT student = (PSTUDENT)malloc(sizeof(STUDENT));
	if (NULL == student || NULL == studentName) {
		fprintf(stderr, "Unable to allocate storage for student");
		exit(EXIT_FAILURE);
	}

	strncpy(studentName->firstName, firstName, NAME_MAX_SIZE);
	strncpy(studentName->middleName, middleName, NAME_MAX_SIZE);
	strncpy(studentName->lastName, lastName, NAME_MAX_SIZE);

	student->studentNumber = studentNumber;
	student->studentName = studentName;


	// APPENDS TO HEAD OF SNAKE
	student->next = *list;
	*list = student;

	return student;
}


void print_student(PSTUDENT student) {
	printf("%d - %s, %s", student->studentNumber,
		student->studentName->firstName, student->studentName->lastName);

	// a string must be defined, but 'empty' strings are only containing 
	// the terminator
	if (student->studentName->middleName[0] != '\0') {
		printf(" %c.", student->studentName->middleName[0]);
	}

	printf("\n");
}

void print_students(PSTUDENT list) {
	while (NULL != list) {
		print_student(list);
		list = list->next;
	}
}
void destroyStudent(PSTUDENT student) {
	if (NULL == student) {
		fprintf(stderr, "Unable to destroy student, was passed a null pointer");
		return;
	}
	// student Name is a nested pointer
	// using memset as I do not trust the OS
	// to properly remove data
	// so doing this ensures sensitive data
	// is overridden
	memset(student->studentName, 0, sizeof(NAME));
	free(student->studentName);
	return;
}


void destroyStudentList(PSTUDENT* list) {
	PSTUDENT current = *list;
	while (NULL != current) {
		PSTUDENT tmp = current;
		destroyStudent(current);
		current = tmp->next;
		memset(tmp, 0, sizeof(STUDENT));
		free(tmp);
	}
}