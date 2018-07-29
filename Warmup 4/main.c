//
//  main.c
//  Warmup 4
//
//  Created by Daniel Hernández on 7/28/18.
//  Copyright © 2018 Daniel Hernández. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commonFunctions.h"
#include "structs.h"
#include "nodeFunctions.h"

bool done;					// Used to loop through the main menu until switch option 4 is selected
int  gradeInput;				// Receives the grade input from the user
int  IdCardInput;				// Receives the ID input from the user
int counter;					// Used to know the quantity of students
int switchInput;				// Used to receive the option selcted from the switch
char nameInput[maxLength];			// Used to receive the raw char input
char nameInputAsString[maxLength];		// Used to reviece the properly formatted string
struct node student;				// Iitializes the node 'student' which itself is the object inside a list that represents each student


int main(int argc, const char * argv[]) {
	while(!done){
		if (!counter)
		switchInput = askInt("\n\nPlease choose one of the following: \n\n1. Enter student's info. \n2. Print all the info saved. \n3. Search student by ID. \n4. Exit.\n\n Option: ", 4);
		else if (counter)
			switchInput = askInt("\n\nPlease choose one of the following: \n\n1. Add student's info. \n2. Print all the info saved. \n3. Search student by ID. \n4. Exit.\n\n Option: ", 4);
		switch (switchInput) {
			case 1:							// Enter/Add student info
				printf("\n\nPlease Enter the following fields: \nName: ");
				scanf("%s", nameInput);
				strcpy(nameInputAsString, nameInput);		// Parses the name as a string
				gradeInput = askInt("Grade: ", 100);		// The second parameter defines the max value
				IdCardInput = askInt("ID: ", 200000000);	// The second parameter defines the max value
				push(&student, nameInput, gradeInput, IdCardInput);
				counter++;					// used to count how many students there are (from the possible students that will fit into the array
				break;
				
			case 2:
				if (counter)
				printList(&student);
				else if (!counter)
					printf("\nNo students yet. Please select option 1 in the main menu\nReturning...");
				break;
				
			case 3:
				IdCardInput = askInt("\nPlease enter student's ID. \nID: ", 200000000);		// asks the user for the ID number
				searchId(&student, IdCardInput);
				break;
			case 4:
				done = true;					// exits the main menu and thus, ends the program
				break;
		}
	}
	
    return 0;
}
