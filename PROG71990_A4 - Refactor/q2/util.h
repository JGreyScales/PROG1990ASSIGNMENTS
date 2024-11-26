#pragma once

// interface for util functions
// Prog71990 - Jackson G - Assignment 4 - 2024-10-31

#include "seats.h"
#include "plane.h"


void number_of_empty_seats(PPLANE);

bool handle_menu_input(const char, PPLANE);

void print_menu(void);

// converts to lower, and returns lowered string
void to_lower(char*, size_t);

// swaps two items in an array, using their index to locate
void swap_two_spaces(PSEAT[12], const unsigned int, const unsigned int);

// retrieves an int from the user
bool get_int_from_user(int*, int, int);

// retrieves a char array from the user
bool get_user_char_array_input(char*);

char get_user_char_input(void);

// returns true if second value is smaller
bool right_is_smaller_of(const int, const int);

void remove_new_lines(char*);