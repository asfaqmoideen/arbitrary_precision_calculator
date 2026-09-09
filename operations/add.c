/* -----------------------------------------------------------------------------------------
Author Name : Asfaq Moideen
Description : Arbitrary Precision Calculator (APC)
--------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include "../include/apc.h"
#include "../include/dll.h"
#include <stdlib.h>

int add_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    if(l_head == NULL || l_tail == NULL || r_head == NULL || r_tail == NULL ){
        printf("Null values in the list of array\n");
        return FAILURE;
    }

    int carry = 0;
    while (l_tail != NULL || r_tail != NULL)
    {   

        int num1 = l_tail == NULL ? 0 : l_tail->data;
        int num2 = r_tail == NULL ? 0 : r_tail->data;

        int num = num1 + num2 + carry;
        
        carry = num/10;
        num = num%10;
        
        dl_insert_first(res_head, res_tail , num);
        
        if (l_tail != NULL) l_tail = l_tail->prev;
        if (r_tail != NULL) r_tail = r_tail->prev;

    }

    if(carry){
        dl_insert_first(res_head, res_tail , carry);
    }

    return SUCCESS;
}