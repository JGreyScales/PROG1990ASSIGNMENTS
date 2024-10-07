#pragma once

// Interface for Student Struct
// Jackson G - Prog71990 - Assignment 3 Question 4 - 2024-10-06

#define NAME_MAX_SIZE 60

typedef struct Name {
	char firstName[NAME_MAX_SIZE];
	char middleName[NAME_MAX_SIZE];
	char lastName[NAME_MAX_SIZE];
} NAME;


typedef struct Student {
	int studentNumber;
	NAME studentName;
} STUDENT;

// C
STUDENT create_student(int, char[NAME_MAX_SIZE], char[NAME_MAX_SIZE], char[NAME_MAX_SIZE]);

//R
void print_student(STUDENT);
void print_students(STUDENT[], int);

//U

//D