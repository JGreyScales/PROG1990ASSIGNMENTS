#define _CRT_SECURE_NO_WARNINGS

// implementation for util functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31


#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

#include "util.h"
#include "seats.h"
#include "plane.h"


// i had an error in the status code where when I ctrl+f'd to replace something
// I set INPUTERROR = SUCCESS = FALSE causing undefined behaviour

// to be honest, I regret choosing the values I did for the status
// however there is no internet at my dorm & im writing this on a small screened laptop on campus
// so I am brute forcing my way through this, with the understanding this may reduce my marks

// this is simply an oversight and improper use of the ctrl+f functionality of the editor
enum statusCode { INPUTERROR = true, SUCCESS = false };


void number_of_empty_seats(PPLANE plane) {
	int counter = 0;
	for (int i = 0; i < SEAT_AMOUNT; i++) {
		if (!plane->seats[i]->assigned) {
			counter++;
		}
	}

	fprintf(stdout, "There are %d empty seats\n", counter);
	return;
}

static void list_of_empty_seats(PPLANE plane) {
	for (int i = 0; i < SEAT_AMOUNT; i++) {
		if (!plane->seats[i]->assigned) {
			fprintf(stdout, "Seat:%d\n", i);
		}
	}
	return;
}

static void print_ordered(PPLANE plane) {
	int buffer = 0;

	// buffer = mode = unsigned int
	fprintf(stdout, "please select a choice from below\n 1) sort by first");
	fprintf(stdout, " name\n2) sort by last name\n 3) for abort\n\n");
	if (get_int_from_user(&buffer, 1, 3)) {
		fprintf(stdout, "Unable to get int from user");
		fprintf(stdout, "Defaulting to sort by first name");
		buffer = 1;
	}
	print_by_order(plane, buffer);
}

static void create_seat_reservation(PPLANE plane) {
	int buffer = 0;
	char firstName[MAX_NAME_SIZE] = { 0 };
	char lastName[MAX_NAME_SIZE] = { 0 };
	fprintf(stdout, "\n\nPlease type the ID you wish to reserve\n");
	fprintf(stdout, "Or type -1 to abort\n");


	// error message handled inside
	if (get_int_from_user(&buffer, -1, 11)) {
		return;
	}

	if (-1 == buffer) {
		fprintf(stdout, "aborting");
		return;
	}

	// seat is already taken
	if (plane->seats[buffer]->assigned) {
		fprintf(stdout, "That seat is already taken!\n");
		return;
	}

	
	fprintf(stdout, "Please type your first name\n");
	if (get_user_char_array_input(firstName)) {
		fprintf(stderr, "Unable to properly assign variable\n");
		return;
	}
	fprintf(stdout, "Please type your last name\n");
	if (get_user_char_array_input(lastName)) {
		fprintf(stderr, "Unable to properly assign variable\n");
		return;
	}

	// SUCCESS to mark as reserved
	create_data(plane->seats[buffer], firstName, lastName, true);
	return;
}

static void delete_seat_reservation(PPLANE plane) {
	int buffer = 0;
	fprintf(stdout, "\n\nPlease type the ID you wish to delete\n");
	if (get_int_from_user(&buffer, 0, 11)) {
		fprintf(stdout, "Unable to read int from user, aborting");
		return;
	}
	remove_data(plane->seats[buffer]);
	return;
}

bool handle_menu_input(const char choosen, PPLANE plane) {
	switch (choosen)
	{
	case 'a':
		number_of_empty_seats(plane);
		break;
	case 'b':
		list_of_empty_seats(plane);
		break;
	case 'c':
		print_ordered(plane);
		break;
	case 'd':
		create_seat_reservation(plane);
		break;
	case 'e':
		delete_seat_reservation(plane);
		break;
	case 'f':
		return false;
		break;
	default:
		fprintf(stderr, "Invalid selection\n");
		break;
	}
	return true;
}

void print_menu(void) {
	printf("\n\n========================================\n");
	printf("===       Seat Assignment Menu       ===\n");
	printf("========================================\n");
	printf("| a) Show number of empty seats        |\n");
	printf("| b) Show list of empty seats          |\n");
	printf("| c) Show alphabetical list of seats   |\n");
	printf("| d) Assign a customer to a seat       |\n");
	printf("| e) Delete a seat assignment          |\n");
	printf("| f) Quit                              |\n");
	printf("========================================\n\n");
	return;
}

// converts to lower, and returns lowered string
void to_lower(char* string, size_t size) {
	// iterates over each character in the string
	for (int c = 0; c <= size; c++) {
		string[c] = tolower(string[c]);
	}
	return;
}

// swaps two items in an array, using their index to locate
void swap_two_spaces(PSEAT seats[12], unsigned int i1, unsigned int i2) {
	PSEAT buffer = seats[i1];
	seats[i1] = seats[i2];
	seats[i2] = buffer;
	return;
}

// retrieves an int from the user
// returns SUCCESS on error
bool get_int_from_user(int* buffer, int lowerBound, int upperBound) {
	if (1 != scanf("%i", buffer)) {
		printf("Invalid Assignment, ensure is of type int\n");
		printf("Value must be greater than or equal to %d and less than or\n", lowerBound);
		printf("equal to %d", upperBound);
		return INPUTERROR;
	}
	if (lowerBound > *buffer || upperBound < *buffer) {
		printf("Invalid range, must be of type int and greater than or equal %d", lowerBound);
		printf(" and less than or equal to %d\n", upperBound);
		return INPUTERROR;
	}
	return SUCCESS;
}

// retrieves a char array from the user
// returns SUCCESS on error
bool get_user_char_array_input(char* buffer) {
	if (1 != scanf("%60s", buffer)) {
		printf("Invalid Assignment, ensure that type is string & length is ");
		printf("less than %i", MAX_NAME_SIZE);
		return INPUTERROR;
	}

	// handles special characters
	size_t size = strlen(buffer);
	char internalBuffer[MAX_NAME_SIZE] = {0};
	strcpy(internalBuffer, buffer);
	to_lower(internalBuffer, size);
	for (int i = 0; i < size; i++) {
		if (ASCII_LOWERED_OFFSET < (int)internalBuffer[i] || ASCII_LOWERED_UPPER_BOUND >(int)internalBuffer[i]) {
			// handle special characters
			// also handles expected characters such as
			// \r & \n
			internalBuffer[i] = '\0';
		}
	}

	return SUCCESS;
}

char get_user_char_input(void) {
	char buffer = ' ';
	// whitespace tells scanf to ignore previous newlines & whitespace
	if (1 != scanf(" %c", &buffer)) {
		fprintf(stdout, "Invalid assignment of buffer");
		return ' ';
	}

	// pushes the file pointer to the end of the "file"
	// this prevents users from entering multiple chars and queueing up commands
	// this instead forces only the first letter to be processed
	// and all the rest ignored on the next iteration
	fseek(stdin, 0, SEEK_END);
	return tolower(buffer);
}


// returns SUCCESS if second value is smaller
bool right_is_smaller_of(const int i1, const int i2) {
	if (i2 < i1) {
		return SUCCESS;
	}
	return false;
}

// replaces all new lines with terminators
void remove_new_lines(char* str) {
	size_t size = strlen(str);
	for (int i = 0; i < size; i++) {
		if ('\n' == str[i]) {
			str[i] = '\0';
		}
	}
}