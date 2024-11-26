#pragma once

// interface for seat functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31

#define MAX_NAME_SIZE	60
#define SEAT_SIZE		sizeof(SEAT)

#include <stdbool.h>


typedef struct seat {
	unsigned int ID;
	bool assigned;
	char firstName[MAX_NAME_SIZE];
	char lastName[MAX_NAME_SIZE];
} SEAT, *PSEAT;

// used to init seats
PSEAT create_seat(const int);
// prints single seat data
bool print_seat(const PSEAT);

// purges customer data, allowing someone else to book the seat
bool remove_data(PSEAT);

// adds customer data, allowing someone to reserve the seat
bool create_data(PSEAT, const char[MAX_NAME_SIZE], const char[MAX_NAME_SIZE],
				bool);

void destroy_seat(PSEAT);