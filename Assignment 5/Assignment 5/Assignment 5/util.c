
#include "util.h"
// PROG71990f24 - Jackson G - Assignment 5 - 2024-11-20
// impli for the utils

bool get_user_char_array_input(char* buffer) {
	if (1 != scanf_s("%59s", buffer, MAX_INPUT_SIZE - 1)) {
		printf("Invalid Assignment, ensure that type is string & length is ");
		printf("less than %i", MAX_INPUT_SIZE);
		return FAILURE;
	}
	return SUCCESS;
}