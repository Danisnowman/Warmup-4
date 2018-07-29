//
//  nodeFunctions.h
//  Warmup 4
//
//  Created by Daniel Hernández on 7/29/18.
//  Copyright © 2018 Daniel Hernández. All rights reserved.
//

#ifndef nodeFunctions_h
#define nodeFunctions_h
#include <stdio.h>
#include <stdbool.h>


bool done;                    // Used to loop through the main menu until switch option 4 is selected
bool noMatch = true;                //
int  gradeInput;                // Receives the grade input from the user
int  IdCardInput;                // Receives the ID input from the user
int counter;                    // Used to know the quantity of students
int switchInput;                // Used to receive the option selcted from the switch
char nameInput[maxLength];            // Used to receive the raw char input
char nameInputAsString[maxLength];        // Used to reviece the properly formatted string
struct node student;                // Iitializes the node 'student' which itself is the object inside a list that represents each student

void printList(node_t * head) {        // Function used to iterate over a list
    node_t * current = head;        // Defines head as the first node
    while (current != NULL) {        // While the current node is not empty, it will print its value
        printf("\nStudent's name: %s\n", current->name);
        printf("Students's grade: %d\n", current->grade);
        printf("Student's ID: %d\n", current->idCard);
        current = current->next;    // Moves unto the next node
    }
    printf("\nThe total amount of students is: %d\n", counter);
}

void searchId(node_t * head, int idCardInput) {        // Function used to iterate over a list
    node_t * current = head;        // Defines head as the first node
    while (current != NULL) {        // While the current node is not empty, it will print its value
        if (current->idCard == idCardInput){
            printf("Student: %s", current->name);
            noMatch = false;
        }
        current = current->next;    // Moves unto the next node
        if (noMatch){
            printf("\nNo match found. Returning...");
            noMatch = false;
        }
    }
    
}

void push(node_t * head, char nameInput[maxLength], int gradeInput, int idCardInput) {
    node_t * current = head;        // Defines head as the first node
    while (current->next != NULL) { // Checks if it is on the last node
        current = current->next;    // Moves to the last node to then
    }
    if (head->idCard == 0) {        // Checks if idCard is 0 to see if node head is empty. a student can have 0 on a grade but not on idCard
        strcpy(head->name, nameInput);
        head->grade = gradeInput;
        head->idCard = idCardInput;
    }else{                    // If head is not empty, it moves to the nex node
        current->next = malloc(sizeof(node_t));
        strcpy(current->next->name, nameInput);
        current->next->grade = gradeInput;
        current->next->idCard = idCardInput;
        current->next->next = NULL;
    }
}


#endif /* nodeFunctions_h */
