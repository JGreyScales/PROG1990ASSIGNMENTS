#define _CRT_SECURE_NO_WARNINGS

//Write a program that prints a table (using ASCII (printable) characters - for
//example : ‘ | ’ and ‘ - ’ ) with each line giving an integer, its cube(a* a* a), its
//square(a* a), and it’s square root(√a); in that column order.The design and
//specific character choice for the table design / presentation are free for you to
//decide - but make it look nice!).Ask the user to enter a lower and upper limit
//for the table, but set limits so that input stays between 5 and 25. Use a for
//loop.


// Jackson G - prog71990 - assignment 2 - question 2 - 2024-09-22

#include <stdio.h>
#include <math.h>

#define INVALID_ASSIGNMENT  1
#define OUT_OF_DOMAIN_ERROR 2

int calculate_cube(int a) {
	return a * a * a;
}

int calculate_square(int a) {
	return a * a;
}

double calculate_squareroot(int a) {
	return sqrt(a);
}


static void print_table(int xInput) {
	for (int x = 1; x <= xInput; x++) {
		printf("\n--------------------\n");
		printf("|%d|%d|%lf|", calculate_cube(x), calculate_square(x), calculate_squareroot(x));
	}
}

int main(void) {

	int userXInput = 0;

	// input
	// x & y must be between 5 and 25, inclusive
	printf("Please print the desired x size\nMust be less 5 <= x <= 25\n");
	if (1 != scanf("%d", &userXInput)) {
		printf("Invalid assignment, must be of type int\n");
		return INVALID_ASSIGNMENT;
	}
	else if (5 > userXInput || 25 < userXInput) {
		printf("value must be between or equal to 5 and 25\n");
		return OUT_OF_DOMAIN_ERROR;
	}

	// process & output
	print_table(userXInput);

	return 0;
}
