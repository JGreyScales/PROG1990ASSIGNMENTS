

//Write a file copy program that takes 2 command line parameters : 1) 
// the name of an existing text file and 
// 2) the name of file to be created by your program.
// 
//The program should use the tolower() function from ctype.h to convert all text
//in the file used as parameter 1 to lowercase as it’s written to the output file (parameter 2).
// 
// Use standard I / O and the text mode.

// Jackson G - PROG71990 - ASSIGNMENT 4 - QUESTION 1 - 2024-10-30
// I made this file while distracted, I did a silly thing with the name
// this is question 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fileOperations.h"


int main(int argc, char** argv) {

	char fileContent[MAX_FILE_SIZE] = {0};

	if (3 != argc) {
		fprintf(stderr, "Usage: %s <existing_file> <file_to_copy_to>", argv[0]);
		exit(EXIT_FAILURE);
	}

	size_t size = read_all_from_file(argv[1], fileContent);
	if (false == write_all_to_file(argv[2], fileContent)) {
		fprintf(stderr, "Error writing to file: %s", argv[2]);
		exit(EXIT_FAILURE);
	}

	return 0;
}