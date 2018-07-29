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

bool done;							// 'done' is used to loop through the main menu until switch option 4 is selected
bool noMatch = true;				//
int  gradeInput;					// 'gradeInput' receives the grade input from the user
int  IdCardInput;					// 'IdCardInput	receives the ID input from the user
char nameInput[maxLength];			// 'nameInput[]' is used to receive the raw char input
char nameInputAsString[maxLength];	// 'nameInputAsString[]' is used to reviece the properly formatted string
struct node student;				// Iitializes the node 'student' which itself is the object inside a list that represents each student


void print_list(node_t * head) {	// Function used to iterate over a list
	node_t * current = head;		// Defines head as the first node
	while (current != NULL) {		// While the current node is not empty, it will print its value
		printf("\nStudent's name: %s\n", current->name);
		printf("Students's grade: %d\n", current->grade);
		printf("Student's ID: %d\n", current->idCard);
		current = current->next;	// Moves unto the next node
	}
}

void push(node_t * head, char nameInput[maxLength], int gradeInput, int idCardInput) {
	node_t * current = head;		// Defines head as the first node
	while (current->next != NULL) { // Checks if it is on the last node
		current = current->next;	// Moves to the last node to then
	}
	if (head->idCard == 0) {		// Chekcs if the head is empty, it uses the 'idCard' value beacuse a student could have 0 on a grade but needs an ID always
		strcpy(head->name, nameInput);
		head->grade = gradeInput;
		head->idCard = idCardInput;
	}else{							// If head is not empty, it moves to the nex node
			current->next = malloc(sizeof(node_t));
			strcpy(current->next->name, nameInput);
			current->next->grade = gradeInput;
			current->next->idCard = idCardInput;
			current->next->next = NULL;
	}
}

int main(int argc, const char * argv[]) {
	while(!done){
		int switchInput = askInt("\n\nPlease choose one of the following: \n\n1. Enter student's info. \n2. Print all the info saved. \n3. Search student by ID. \n4. Exit.\n\n Option: ", 4);
		switch (switchInput) {
			case 1:
				printf("\n\nPlease Enter the following fields: \nName: ");
				scanf("%s", nameInput);
				strcpy(nameInputAsString, nameInput);		// Parses the name as a string
				gradeInput = askInt("Grade: ", 100);		// The second parameter defines the max value
				IdCardInput = askInt("ID: ", 200000000);	// The second parameter defines the max value
				push(&student, nameInput, gradeInput, IdCardInput);
				//counter++;								// used to count how many students there are (from the possible students that will fit into the array
				break;
				
			case 2:
				print_list(&student);
				break;
				
			case 3:
				IdCardInput = askInt("\nPlease enter student's ID. \nID: ", 200000000);				// asks the user for the ID number
				/*for (int i = 0; i < maxStudents; i++) {
					if (id == student[i].idCard) {											// checks if there's an existing id that matches the input
						printf("\nFound who you are searching for. \nStudent: %s\n", student[i].name);
						noMatch = false;
					}
				}
				if (noMatch)
					printf("\nNo match found. Returning...");
				break;
				*/
			case 4:
				done = true;		// exits the main menu and thus, ends the program
				 break;
		}
	}
	
    return 0;
}
