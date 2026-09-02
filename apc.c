#include<stdio.h>
#include<string.h>
#include"dll.h"

int create_list(char *input, Dlist **head, Dlist **tail){

    *head = NULL;
    *tail = NULL;

    int len = strlen(input);


    for(int i = 0 ; i < len ; i++){
        int num = input[i] - 48;

        if(dl_insert_last(head, tail, num) == FAILURE){
            printf("Memory Allocation Failure\n");
            return FAILURE;
        };
    }


    return SUCCESS;
}

int add_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    if(l_head == NULL || l_tail == NULL || r_head == NULL || r_tail == NULL ){
        printf("Null values in the list of array\n");
        return FAILURE;
    }

    int carry = 0;
    while (l_tail != NULL || r_tail != NULL)
    {   
        printf("l: %d, r: %d\n",l_tail->data, r_tail->data );

        int num1 = l_tail == NULL ? 0 : l_tail->data;
        int num2 = r_tail == NULL ? 0 : r_tail->data;
        int num = num1 + num2 + carry;
        
        carry = num/10;
        num = num%10;
        
        
        printf("l: %d, r: %d\n",l_tail->data, r_tail->data );
        dl_insert_first(res_head, res_tail , num);
        
        if (l_tail != NULL) l_tail = l_tail->prev;
        if (r_tail != NULL) r_tail = r_tail->prev;

    }

    dl_insert_first(res_head, res_tail , carry);
    return SUCCESS;
}

// Slist* subtract_lists(Slist* op1, Slist* op2){

//     if(op1 == NULL || op2 == NULL){
//         return NULL;
//     }

//     Slist *l_temp = op1, *r_temp = op2, *result = NULL;
//     int borrow = 0;

//     while (l_temp != NULL || r_temp != NULL)
//     {   
//         printf("Borrow : %d", borrow);
//         int num1 = l_temp == NULL ? 0 : l_temp->data;
//         int num2 = r_temp == NULL ? 0 : r_temp->data;

//         if(borrow){
//             num1--;
//             borrow = 0;
//         }

//         if(num1 < num2){
//             borrow = 1;
//             num1+=10;
//         }

//         int diff = num1 - num2;
//         printf("Diff : %d\n", diff);
//         insert_at_first(&result, diff);
        
//         if (l_temp != NULL) l_temp = l_temp->link;
//         if (r_temp != NULL) r_temp = r_temp->link;

//     }

//     // insert_at_first(&result, carry);

//     return result;
    
// }
