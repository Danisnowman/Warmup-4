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

bool done;
bool noMatch = true;
int id, gradeInput, IdCardInput;
char nameInput[maxLength], nameInputAsString[maxLength];
struct node student;


void print_list(node_t * head) {			// Function used to iterate over a list
	node_t * current = head;
	while (current != NULL) {
		printf("\nStudent's name: %s\n", current->name);
		printf("Students's grade: %d\n", current->grade);
		printf("Student's ID: %d\n", current->idCard);
		current = current->next;
	}
}

void push(node_t * head, char nameInput[maxLength], int gradeInput, int idCardInput) {
	node_t * current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	
	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	strcpy(current->next->name, nameInput);
	//current->next->name = 2;
	current->next->grade = gradeInput;
	current->next->idCard = idCardInput;
	current->next->next = NULL;
}

int main(int argc, const char * argv[]) {
	/*node_t * head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}
	
	head->data = 1;
	head->next = NULL;*/
	
	/**********************************************/
	while(!done){
		int switchInput = askInt("\n\nPlease choose one of the following: \n\n1. Enter student's info. \n2. Print all the info saved. \n3. Search student by ID. \n4. Exit.\n\n Option: ", 4);
		switch (switchInput) {
			case 1:
				printf("\n\nPlease Enter the following fields: \nName:");
				scanf("%s", nameInput);
				strcpy(nameInputAsString, nameInput);
				gradeInput = askInt("Grade: ", 100);
				IdCardInput = askInt("ID: ", 200000000);	// the second parameter on askInt() and askDouble() is the max value the user can enter.// the second parameter on askInt() and askDouble() is the max value the user can enter.
				push(&student, nameInput, gradeInput, IdCardInput);
				//counter++;									// used to count how many students there are (from the possible students that will fit into the array
				break;
				
			case 2:
				print_list(&student);
				break;
				
			case 3:
				id = askInt("\nPlease enter student's ID. \nID: ", 200000000);				// asks the user for the ID number
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
