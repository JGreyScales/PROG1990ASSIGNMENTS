#pragma once

// Interface for Student Struct
// Jackson G - Prog71990 - Assignment 3 Question 4 - 2024-10-06

#define NAME_MAX_SIZE 60

typedef struct Name {
	char firstName[NAME_MAX_SIZE];
	char middleName[NAME_MAX_SIZE];
	char lastName[NAME_MAX_SIZE];
} NAME, *PNAME;


typedef struct Student {
	int studentNumber;
	PNAME studentName;
	struct student* next;
} STUDENT, *PSTUDENT;

// C
PSTUDENT create_student(PSTUDENT*, int, char[NAME_MAX_SIZE], char[NAME_MAX_SIZE], char[NAME_MAX_SIZE]);

//R
void print_student(PSTUDENT);
void print_students(PSTUDENT);

//U

//D
void destroyStudent(PSTUDENT);
void destroyStudentList(PSTUDENT*);