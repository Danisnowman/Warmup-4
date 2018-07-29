//
//  structs.h
//  Warmup 2
//
//  Created by Daniel Hernández on 7/25/18.
//  Copyright © 2018 Daniel Hernández. All rights reserved.
//

#ifndef structs_h
#define structs_h
#include "commonFunctions.h"
struct saveStudent {
    char	name[maxLength];
    int		grade;
	int 	idCard;
};

typedef struct node {
    char name[maxLength];
    int grade;
    int idCard;
    int data;
    struct node * next;
} node_t;

#endif /* structs_h */
