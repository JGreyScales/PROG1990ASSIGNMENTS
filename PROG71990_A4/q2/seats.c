#define _CRT_SECURE_NO_WARNINGS

// implementation for seat functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31

#include <memory.h> // needed for memset
#include <stdbool.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#include "seats.h"
#include "util.h"

enum statusCode {NULLERROR = -1, BOOLNULLERROR, FAILURE = true, SUCCESS = false};
enum assignedStatus { UNASSIGNED = 0, ASSIGNED = 1 };

// used to init seats
PSEAT create_seat(const int id) {
	PSEAT newSeat = (PSEAT)malloc(SEAT_SIZE);
	if (NULL == newSeat) {
		fprintf(stderr, "Unable to allocate memory for seat\n");
		return NULL;
	}
	memset(newSeat, 0, SEAT_SIZE);
	newSeat->assigned = false;
	newSeat->ID = id;
	strncpy(newSeat->firstName, "\0", MAX_NAME_SIZE);
	strncpy(newSeat->lastName, "\0", MAX_NAME_SIZE);
	return newSeat;

}
// prints single seat data
bool print_seat(const PSEAT seat) {
	if (NULL == seat) {
		fprintf(stderr, "Seat is null, unable to print\n");
		return BOOLNULLERROR;
	}

	fprintf(stdout, "Name: %s %s ID: %d", seat->firstName, seat->lastName, seat->ID);
	return SUCCESS;
}

// purges customer data, allowing someone else to book the seat
bool remove_data(PSEAT seat) {
	if (NULL == seat) {
		fprintf(stderr, "Seat is null, unable to remove data\n");
		return BOOLNULLERROR;
	}

	if (!seat->assigned) {
		fprintf(stderr, "Seat already unassigned, unable to delete data\n");
		return FAILURE;
	}

	int buffer = seat->ID;

	memset(seat, 0, SEAT_SIZE);
	strncpy(seat->firstName, "\0", MAX_NAME_SIZE);
	strncpy(seat->lastName, "\0", MAX_NAME_SIZE);
	seat->assigned = false;
	seat->ID = buffer;

	fprintf(stdout, "Seat unassigned\n");
	return SUCCESS;
}

// adds customer data, allowing someone to reserve the seat
bool create_data(PSEAT seat, const char setFirstName[MAX_NAME_SIZE], 
				const char setLastName[MAX_NAME_SIZE], bool assigned) {
	if (NULL == seat) {
		fprintf(stderr, "Seat is null, unable to add data\n");
		return BOOLNULLERROR;
	}

	strncpy(seat->firstName, setFirstName, MAX_NAME_SIZE);
	strncpy(seat->lastName, setLastName, MAX_NAME_SIZE);
	seat->assigned = assigned;


	return SUCCESS;
}
