/* -----------------------------------------------------------------------------------------
Author Name : Asfaq Moideen
Description : Arbitrary Precision Calculator (APC)
--------------------------------------------------------------------------------------------*/


#ifndef APC_H
#define APC_H

#include"dll.h"

#define SUCCESS 0
#define FAILURE -1

/* Creates a double linked list of integers scrapped from the char * input given*/
int create_list(char *input, Dlist **head, Dlist **tail);

/* Stores the result of addition of two double linkedlist of integers in a result double linkedlist*/
int add_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail);

/* Stores the result of subtraction of two double linkedlist of integers in a result double linkedlist*/
int subtract_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail);

/* Stores the result of division of two double linkedlist of integers in a result double linkedlist*/
int divide_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail);

/* Stores the result of division of two double linkedlist of integers in a result double linkedlist*/
int mulitpy_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail);

/* Compaers the list of integer stored in a double linked list, returns 0 if equal, 1 if num1 if greater and -1 if lessser*/
int compare_lists(Dlist *l_head, Dlist *r_head);

/* Removes the leading zeros for the given double linked list*/
void remove_leading_zeros(Dlist **head, Dlist **tail);

/* stores the product of given number multiplied by each node of given linked list*/
int multiply_single_number(int num, Dlist* node_tail, Dlist **res_head, Dlist **res_tail);


#endif 
