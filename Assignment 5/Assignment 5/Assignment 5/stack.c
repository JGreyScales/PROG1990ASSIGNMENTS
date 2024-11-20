// PROG71990f24 - Jackson G - Assignment 5 - 2024-11-20
// impli for the stack

#include "stack.h"

PSTACK init_stack(void) {
	PSTACK newS = (PSTACK)malloc(sizeof(STACK));
	if (NULL == newS) {
		fprintf(stderr, "Unable to allocate room for stack");
		return NULL;
	}
	newS->top = -1;
	memset(newS->stackArr, 0, sizeof(newS->stackArr));
	return newS;
}

bool pop_stack(PSTACK stack) {
	if (NULL == stack || is_stack_empty(stack)) {
		fprintf(stderr, "Stack is null or empty, cannot pop");
		return FAILURE;
	}

	// I opted to use \0 to prevent malformed strings from allowing
	// string operators to crawl the software memory pass the old location
	stack->stackArr[stack->top--] = '\0';
	return SUCCESS;
}

bool destroy_stack(PSTACK stack) {
	if (NULL == stack) {
		fprintf(stderr, "stack is null, cannot destroy");
		return FAILURE;
	}

	// makes sure we don't leave data in memory
	while (!is_stack_empty(stack)) {
		pop_stack(stack);
	}

	free(stack);
	return SUCCESS;
}

bool print_stack(PSTACK stack) {
	if (NULL == stack) {
		fprintf(stderr, "stack is null, cannot print");
		return FAILURE;
	}

	while (!is_stack_empty(stack)) {
		fprintf(stdout, "%c", stack->stackArr[stack->top]);
		pop_stack(stack);
	}
	fprintf(stdout, "\n");
	return SUCCESS;
}

bool is_stack_empty(PSTACK stack) {
	return (-1 == stack->top);
}


bool is_stack_full(PSTACK stack) {
	return (MAX_INPUT_SIZE == stack->top);
}

bool add_string_to_stack(PSTACK stack, char* dataChar) {
	// +1 to include terminator, to simplify the for loop
	size_t length = strlen(dataChar) + 1;
	if (NULL == stack || 0 > length || MAX_INPUT_SIZE + 1 < length) {
		fprintf(stderr, "data is out of bounds of stack, or stack is null");
		return FAILURE;
	}
	if (is_stack_empty(stack)) {
		stack->top = 0;
	}

	for (size_t i = 0; i < length; i++) {
		if (!push_stack(stack, dataChar[i])) {
			return FAILURE;
		}
	}
	return SUCCESS;
}

bool push_stack(PSTACK stack, char dataChar) {
	if (NULL == stack || is_stack_full(stack)) {
		fprintf(stderr, "data is out of bounds of stack, or stack is null");
		return FAILURE;
	}

	stack->stackArr[stack->top++] = dataChar;
	return SUCCESS;
}

// returns \0 on failure, or if top char is \0
char peek_stack(PSTACK stack) {
	if (NULL == stack || is_stack_empty(stack)) {
		fprintf(stderr, "stack is null, or stack is empty");
		return '\0';
	}
	return stack->stackArr[stack->top];
}
