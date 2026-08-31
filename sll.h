#ifndef SLL_H
#define SLL_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *link;
}Slist;

int insert_at_last(Slist **head, data_t );
int insert_at_first(Slist **head, data_t );
int insert_before(Slist **head, int gdata, int n_data);
void print_list(Slist *head);

#endif