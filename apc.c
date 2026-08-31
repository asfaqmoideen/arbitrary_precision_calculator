#include<stdio.h>
#include<string.h>
#include "sll.h"

Slist * create_list(char *input){

    Slist *head = NULL;

    int len = strlen(input);


    for(int i = 0 ; i < len ; i++){
        int num = input[i] - 48;
        insert_at_last(&head, num);
    }


    return head;
}

Slist* add_lists(Slist* op1, Slist* op2){

    if(op1 == NULL || op2 == NULL){
        return NULL;
    }

    Slist *l_temp = op1, *r_temp = op2, *result = NULL ; 
    int carry = 0;
    while (l_temp != NULL || r_temp != NULL)
    {   
        int num1 = l_temp == NULL ? 0 : l_temp->data;
        int num2 = r_temp == NULL ? 0 : r_temp->data;
        int num = num1 + num2 + carry;

        carry = num/10;
        num = num%10;


        insert_at_first(&result, num);
        
        if (l_temp != NULL) l_temp = l_temp->link;
        if (r_temp != NULL) r_temp = r_temp->link;

    }

    insert_at_first(&result, carry);
    return result;
}

Slist* subtract_lists(Slist* op1, Slist* op2){

    if(op1 == NULL || op2 == NULL){
        return NULL;
    }

    Slist *l_temp = op1, *r_temp = op2, *result = NULL;
    int borrow = 0;

    while (l_temp != NULL || r_temp != NULL)
    {   
        printf("Borrow : %d", borrow);
        int num1 = l_temp == NULL ? 0 : l_temp->data;
        int num2 = r_temp == NULL ? 0 : r_temp->data;

        if(borrow){
            num1--;
            borrow = 0;
        }

        if(num1 < num2){
            borrow = 1;
            num1+=10;
        }

        int diff = num1 - num2;
        printf("Diff : %d\n", diff);
        insert_at_first(&result, diff);
        
        if (l_temp != NULL) l_temp = l_temp->link;
        if (r_temp != NULL) r_temp = r_temp->link;

    }

    // insert_at_first(&result, carry);

    return result;
    
}
Slist* multiply_lists(Slist* op1, Slist* op2){

}
Slist* divide_lists(Slist* op1, Slist* op2){

}