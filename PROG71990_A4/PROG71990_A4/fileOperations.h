#pragma once

#include <stdbool.h>

//


// not sure how to make these dynamic nicely
// maybe hasnt been covered in class, or maybe im missing something
// any feedback would be apperciated 


//
#define MAX_FILE_SIZE 1000
#define MAX_LINE_SIZE 100

//interface for file functions
// Jackson G - PROG71990 - ASSIGNMENT 4 - QUESTION 1 - 2024-10-30

size_t read_all_from_file(const char*, char*);
bool write_all_to_file(const char*, const char*);
