#define _CRT_SECURE_NO_WARNINGS

// implementation for plane functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31



#include <memory.h> // needed for memset
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "seats.h"
#include "plane.h"
#include "util.h"

enum statusCode { NULLERROR = -1, BOOLNULLERROR = true, SUCCESS = false };

// used to init planes
// returns NULL on error
PPLANE create_plane(PSEAT seats[SEAT_AMOUNT]) {
	PPLANE newPlane = (PPLANE)malloc(PLANE_SIZE);
	if (NULL == newPlane) {
		fprintf(stderr, "Unable to allocate memory for plane\n");
		return NULL;
	}
	memset(newPlane, 0, PLANE_SIZE);

	for (int i = 0; i < SEAT_AMOUNT; i++) {
		newPlane->seats[i] = seats[i];
	}

	return newPlane;
}

// prints a table of open 
void print_seat_table(const PPLANE plane) {
	if (NULL == plane || NULL == plane->seats) {
		fprintf(stderr, "Seats or Plane is NULL and cannot be parsed");
		return;
	}

	for (int i = 0; i < SEAT_AMOUNT; i++) {
		print_seat(plane->seats[i]);
		fprintf(stdout, "\n");
	}

}



// this function uses a very scuffed & homebrewed bubble sort algorithm
// prints a list of seats ordered by name
void print_by_order(const PPLANE plane, const unsigned int mode) {
	if (NULL == plane || NULL == plane->seats) {
		fprintf(stderr, "Seats or Plane is NULL and cannot be parsed");
		return;
	}
	// lower all letters
	// convert the letters to their ascii ID
	// since all letters are lowered, offset = 97
	// special characters will break, input handled elsewhere

	// mode 1 = first name
	// mode 2 = last name

	//slot all values as were given
	// go through each on, compare neighbor to the right, if needed swap
	// loop until 0 changes made on loop
	PSEAT internalSeats[SEAT_AMOUNT] = { 0 };
	int ticker = 0;
	for (int i = 0; i < SEAT_AMOUNT; i++) {
		if ('\0' != plane->seats[i]->firstName[0]) {
			internalSeats[ticker] = plane->seats[i];
			ticker++;
		}
	}


	bool flag = false;
	do {
		// exit condition
		flag = false;

		// my brain is tired, and this is to ensure I don't make a silly mistake
		// where data is leftover on iterations	
		char leftStr[MAX_NAME_SIZE] = { 0 };
		char rightStr[MAX_NAME_SIZE] = { 0 };

		// -1 is because we are going to directly compare the neighbor (+1)
		// and it would overflow if we did not

		// i = int
		for (int i = 0; i < ticker - 1; i++) {
			// handles mode
			switch (mode)
			{
			case 1:
				strcpy(leftStr, internalSeats[i]->firstName);
				strcpy(rightStr, internalSeats[i + 1]->firstName);

				break;
			case 2:
				strcpy(leftStr, internalSeats[i]->lastName);
				strcpy(rightStr, internalSeats[i + 1]->lastName);
				break;
			// handles the abort
			case 3:
				return;
			default:
				fprintf(stderr, "error parsing mode");
				return;
			}

			

			// convert to lower, get size of strings
			size_t leftStrSize = strlen(leftStr);
			size_t rightStrSize = strlen(rightStr);

			to_lower(leftStr, leftStrSize);
			to_lower(rightStr, rightStrSize);
			
			int index = 0;
			int leftValue = (int)leftStr[index];
			int rightValue = (int)rightStr[index];

			// compares chars in order
			// if the two chars are the same
			// it looks at the next one, until the end of the string
			// once end of the string is reached
			// it gives up and keeps them in their current place
			 while (leftValue == rightValue && index < leftStrSize && index < rightStrSize) {
				leftValue = (int)leftStr[index];
				rightValue = (int)rightStr[index];
				index++;
			}
			
			// if right side is larger than left side, swap
			if (right_is_smaller_of(leftValue, rightValue)) {
				// marks to the system that a change was made and that
				// the system should recheck the list
				flag = true;
				swap_two_spaces(internalSeats, i, i + 1);
			}
		}


	} while (flag);

	// only prints the filled and sorted seats
	for (int i = 0; i < ticker; i++) {
		printf("Name: %s %s ID: %d\n", internalSeats[i]->firstName, internalSeats[i]->lastName,
									 internalSeats[i]->ID);
	}

	// shows how many empty one exist, that were not sorted
	number_of_empty_seats(plane);

	return;

}
// returns true on error
bool store_to_file(const PPLANE plane, const char* filename) {
	FILE* fp = fopen(filename, "w");
	if (NULL == fp) {
		fprintf(stderr,  "Unable to open file %s to write to", filename);
		return BOOLNULLERROR;
	}

	for (int i = 0; i < SEAT_AMOUNT; i++) {
		fprintf(fp, "%s\n", plane->seats[i]->firstName);
		fprintf(fp, "%s\n", plane->seats[i]->lastName);
		fprintf(fp, "%d\n", plane->seats[i]->assigned);
	}

	fclose(fp);
	return SUCCESS;
}

PPLANE read_from_file(const char* filename) {

	bool assigned = false;
	PSEAT seats[SEAT_AMOUNT] = { 0 };
	char firstName[MAX_NAME_SIZE] = "";
	char lastName[MAX_NAME_SIZE] = "";


	FILE* fpread = fopen(filename, "r");
	if (NULL == fpread) {
		fprintf(stderr, "Unable to open file %s to read, creating", filename);
		fprintf(stderr, " plane manually");
		for (int i = 0; i < SEAT_AMOUNT; i++) {
			seats[i] = create_seat(i);
		}
	}
	else {



		for (int i = 0; i < SEAT_AMOUNT; i++) {
			seats[i] = create_seat(i);

			fgets(firstName, MAX_NAME_SIZE, fpread);
			fgets(lastName, MAX_NAME_SIZE, fpread);

			remove_new_lines(firstName);
			remove_new_lines(lastName);

			// ID can be assumed, since when writing to the file we write in order
			// of index
			// which is also used when creating the seats
			// aka index order = id order
			int intBuffer = 0;
			if (1 != fscanf(fpread, "%d", &intBuffer)) {
				fprintf(stderr, "Unable to check assignment status of seat %d", i);
				assigned = false;
			}
			else {
				assigned = (bool)intBuffer;
			}
			fgetc(fpread);
			create_data(seats[i], firstName, lastName, assigned);
		}
		fclose(fpread);
	}

	return create_plane(seats);
}