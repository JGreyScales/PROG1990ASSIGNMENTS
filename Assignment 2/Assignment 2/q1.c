#define _CRT_SECURE_NO_WARNINGS

//Write a program that asks the user to enter an integer and then prints all
//the integers starting at the value entered by the user up to a value 16 more
//that the value entered by the user. (That is, if the user were to input 20, the
//output runs from 20 to 36 (inclusive).) Be sure to separate each output value
//by a newline.

// Jackson G - prog71990 - assignment 2 - question 2 - 2024-09-22

#include <stdio.h>

#define INVALID_ASSIGNMENT 1

int main(void) {
	//input
	int userInteger = 0;


	printf("Please input an Integer value\n");
	if (1 != scanf("%d", &userInteger)) {
		printf("Invalid type, please ensure is of type int\n");
		return INVALID_ASSIGNMENT;
	}

	//process

	for (int i = userInteger; i <= userInteger + 16; i++) {
		printf("Value: %d\n", i);
	}

	return 0;
}