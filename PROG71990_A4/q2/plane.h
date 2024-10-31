#pragma once

// interface for plane functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31

#define PLANE_SIZE					sizeof(PLANE)
#define ASCII_LOWERED_OFFSET		97
#define ASCII_LOWERED_UPPER_BOUND	122
#define SEAT_AMOUNT					12

#include "seats.h"

typedef struct plane {
	PSEAT seats[SEAT_AMOUNT];
} PLANE, *PPLANE;

// used to init planes
PPLANE create_plane(PSEAT[SEAT_AMOUNT]);

// prints a table of open seats
void print_seat_table(const PPLANE);

// prints a list of seats ordered by name
void print_by_order(const PPLANE, const unsigned int mode);

void destroy_plane(PPLANE);

bool store_to_file(const PPLANE, const char*);

PPLANE read_from_file(const char*);