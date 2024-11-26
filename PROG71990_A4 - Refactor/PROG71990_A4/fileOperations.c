//implementations for file functions
// Jackson G - PROG71990 - ASSIGNMENT 4 - QUESTION 1 - 2024-10-30

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "fileOperations.h"

static void to_lower(char* fileContent) {

	// this removes the size constrant, and depends on the string being terminated properly
	size_t ticker = 0;
	while ('\0' != fileContent[ticker]) {
		fileContent[ticker] = tolower(fileContent[ticker++]);
	}

	//// iterates over each character in the string
	//for (int c = 0; c <= size; c++) {
	//	fileContent[c] = tolower(fileContent[c]);
	//}
	return;
}



size_t read_all_from_file(const char* filename, char* fileContent) {

	FILE* fpread = fopen(filename, "r");
	char buffer[MAX_LINE_SIZE] = { 0 };
	char bufferOld[MAX_LINE_SIZE] = { 0 };
	char* result = {0};
	if (NULL == fpread) {
		fprintf(stderr, "Unable to open %s", filename);
		exit(EXIT_FAILURE);
	}

	do {
		result = fgets(buffer, MAX_LINE_SIZE, fpread);
		if (0 == strcmp(buffer, bufferOld)) {
			result = NULL;
		}
		else {
			strcat_s(fileContent, MAX_LINE_SIZE, buffer);
			strcpy_s(bufferOld, MAX_LINE_SIZE, buffer);
		}
	} while (NULL != result);
		

	fclose(fpread);

	size_t size = strlen(fileContent);
	to_lower(fileContent, size);

	return size;
}

bool write_all_to_file(const char* filename, const char* fileContent) {

	FILE* fp = fopen(filename, "w");
	if (NULL == fp) {
		fprintf(stderr, "Unable to open %s", filename);
		return false;
	}

	int bytesWritten = fprintf(fp, "%s", fileContent);
	fclose(fp);
	if (0 == bytesWritten) {
		return false;
	}

	return true;
}
