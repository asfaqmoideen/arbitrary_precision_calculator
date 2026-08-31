#ifndef APC_H
#define APC_H

#include"sll.h"

Slist* create_list(char *input);

Slist* add_lists(Slist* op1, Slist* op2);
Slist* subtract_lists(Slist* op1, Slist* op2);
Slist* multiply_lists(Slist* op1, Slist* op2);
Slist* divide_lists(Slist* op1, Slist* op2);


#endif 
