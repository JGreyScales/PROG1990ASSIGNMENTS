//The Colossus Airlines fleet consists of one plane with a seating capacity of
//12. It makes one flight daily.Write a seating reservation program with the
//following features :
// 
//(a)The program uses an array of 12 structures.Each structure should hold
//a seat identification number, a marker that indicates whether the seat is
//assigned, the last name of the seat holder, and the first name of the seat
//holder.
//1
//(b)The program displays the following menu :
//To choose a function, enter its letter label :
//a) Show number of empty seats
//b) Show list of empty seats
//c) Show alphabetical list(by passenger name) of seats
//d) Assign a customer to a seat assignment
//e) Delete a seat assignment
//f) Quit
// 
//(c) The program successfully executes the promise of each command on its
//menu.
// 
//(d)Choice c) will list the passengers in alphabetic order, either by first or last
//name(ask user for first or last name ordering).
// 
//(e)Choices d) and e) require additional input, and each should enable the
//user to enter data or abort the action.
// 
//(f)After executing a particular function(options a) - e)), the program should
//print the menu again and wait for input.Upon selecting f), the program
//should exit.
// 
//(g)Data is saved in a file between runs.The name and format of the file need
//not be known to the user.When the program is started(or restarted), it
//will first attempt to read the data file and populate itself with that data;
//if there is no existing datafile, the program will create a new (empty)
//datafile with no data populated.



//internal notes so I don't forget stuff
// no need to mark or review

//util
//to_lower(seat)
//swap_two_spaces(arr, index1, index2)
//get_int_from_user(*int)
//
//
//
//plane struct
//12 seats
//
//print seats(plane)
//order seats(first or last, plane)
//store_to_file(plane)
//read_from_file
//
//
//
//seat struct
//ID
//Assigned bool
//Last name
//First name
//
//
//print seat
//
//// allow aborts
//delete reservation
//create reservation
//
//
//// try to read from file, hardcoded name
//(do while loop)
////menu & user input
// 
// each user input should be put into a do while loop
// 
//// save file after each loop





// Prog71990 - Jackson G - Assignment 4 - 2024-10-31
// const used to signify the data will not be modified within a func

// originally written in one sitting on 2024-10-31

#include <stdio.h>

#include "util.h"
#include "seats.h"
#include "plane.h"

int main(void) {
	char storageFile[16] = "storagefile.txt";
	char choosen = 'g';
	bool menuLoop = true;

	PPLANE plane = read_from_file(storageFile);
	do {
		print_menu();
		choosen = get_user_char_input();
		menuLoop = handle_menu_input(choosen, plane);

		store_to_file(plane, storageFile);
	} while (menuLoop);
	return 0;
}