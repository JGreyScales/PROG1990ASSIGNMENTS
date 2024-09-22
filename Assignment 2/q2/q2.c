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

#define INVALID_ASSIGNMENT  1
#define OUT_OF_DOMAIN_ERROR 2

static int calculate_cube(int a) {
	return a * a * a;
}

static int calculate_square(int a) {
	return a * a;
}

static float calculate_squareroot(int a) {
	// unsure if we are allowed to use math.h
	// if we are, I would've just done pow(a, 0.5)

	// accuracy of our final result
	float tolerance = 0.01f;

	// float is required for Babylonian method
	float calculatedSquare = (float)a;


	// Babylonian method for square approximation
	while ((calculatedSquare - a / calculatedSquare) > tolerance) {
		calculatedSquare = (calculatedSquare + a / calculatedSquare) / 2;
	}
	return calculatedSquare;
}


static int print_table(int xInput, int yInput) {
	printf("ALL CALCULATIONS DONE USING THE AREA OF THE RECTANGLE (x * y)\n");
	for (int y = 1; y <= yInput; y++) {
		printf("|");
		for (int x = 0; x <= xInput; x++) {

			if (xInput == x) {
				printf("|");
				printf(" cube: %d ", calculate_cube(x * y));
				printf("square: %d ", calculate_square(x * y));
				printf("squareroot: %.2f\n", calculate_squareroot(x * y));
			}
			if (0 < x && xInput > x) {
				printf("-");
			}
		}

	}

	return 0;
}

int main(void) {

	int x = 0;
	int y = 0;

	// input
	printf("Please print the desired x size\nMust be less 5 <= x <= 25\n");
	if (1 != scanf("%d", &x)) {
		printf("Invalid assignment, must be of type int\n");
		return INVALID_ASSIGNMENT;
	}
	else if (5 > x || 25 < x) {
		printf("value must be between or equal to 5 and 25\n");
		return OUT_OF_DOMAIN_ERROR;
	}

	printf("Please print the desired y size\nMust be less 5 <= y <= 25\n");
	if (1 != scanf("%d", &y)) {
		printf("Invalid assignment, must be of type int\n");
		return INVALID_ASSIGNMENT;
	}
	else if (5 > y || 25 < y) {
		printf("value must be between or equal to 5 and 25\n");
		return OUT_OF_DOMAIN_ERROR;
	}


	// process & output
	print_table(x, y);

	return 0;
}