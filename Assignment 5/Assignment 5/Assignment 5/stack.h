#pragma once
// PROG71990f24 - Jackson G - Assignment 5 - 2024-11-20
// interface for the stack

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 60


typedef struct stack {
	char stackArr[MAX_INPUT_SIZE];
	unsigned int top;
} STACK, *PSTACK;

enum STATUS { SUCCESS = true, FAILURE = false };

PSTACK init_stack(void);

bool pop_stack(PSTACK);
bool destroy_stack(PSTACK);
bool print_stack(PSTACK);
bool is_stack_empty(PSTACK);
bool is_stack_full(PSTACK);
bool add_string_to_stack(PSTACK, char*);
bool push_stack(PSTACK, char);

char peek_stack(PSTACK);

