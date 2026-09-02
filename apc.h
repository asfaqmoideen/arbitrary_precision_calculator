#ifndef APC_H
#define APC_H

#include"dll.h"

#define SUCCESS 0
#define FAILURE -1


int create_list(char *input, Dlist **head, Dlist **tail);

int add_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail);

#endif 
