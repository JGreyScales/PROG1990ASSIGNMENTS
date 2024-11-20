
//The stack is another collection type in the list family.In a stack, additions and
//deletions can be made from only one end of the list.Items are said to be “pushed
//onto” the top of the stack and to be “popped off” the stack.Therefore, the stack
//is a LIFO structure(that is, last in, first out).
//a) Devise an ADT for a stack.
//b) Devise a C programming interface for a stack, i.e., a stack.h header file.Your
//stack should not arbitrarily(without some rational requirement that holds up
//	to scrutiny) add constraints(ie : max depth of stack).
//	c) Write a program that asks the user to input a string.The program then should
//	push the characters of the string onto a stack(of characters), one by one, and
//	then pop the characters from the stack and display them.This results in
//	displaying the string in reverse order.


// ADT 2024-11-20
// Stack:
	// init_stack():
		// creates an empty stack
	// pop_stack()
		// pops the last entered item in the stack (last in, first out)
	// destroy_stack()
		// purges stack from memory
	// print_stack()
		// prints the stack, pops each character after print
	// is_stack_empty()
		// returns SUCCESS if the stack is empty
	// is_stack_full()
		// returns if the stack is full
	// peek
		// peeks the top item without popping it
		// online resources say this is defined in basic stack operations
		// even though it wont be used in this project
		// https://www.geeksforgeeks.org/implement-stack-in-c/
	// push_stack()
		// pushes a char or escape sequence into the stack and returns the new current
	// add_string_to_stack()
		// parses a string and offloads the push to push_stack


// PROG71990f24 - Jackson G - Assignment 5 - 2024-11-20-4:19pm


#include "stack.h"
#include "util.h"

int main(void) {
	PSTACK stack = init_stack();
	if (NULL == stack) {
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "Please input a string:\n");
	char buffer[MAX_INPUT_SIZE] = { 0 };
	if (!get_user_char_array_input(&buffer)) {
		exit(EXIT_FAILURE);
	}

	if (!add_string_to_stack(stack, buffer)) {
		exit(EXIT_FAILURE);
	}

	if (!print_stack(stack)) {
		exit(EXIT_FAILURE);
	}

	destroy_stack(stack);

	return 0;
}