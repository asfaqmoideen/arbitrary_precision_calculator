/* -----------------------------------------------------------------------------------------
Author Name : Asfaq Moideen
Description : Arbitrary Precision Calculator (APC)
--------------------------------------------------------------------------------------------*/


#include<stdio.h>
#include<string.h>
#include "../include/apc.h"
#include "../include/dll.h"
#include <stdlib.h>


int subtract_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    int is_subtractable = !(l_head->sign ^ r_head->sign);
    if(is_subtractable){
        return subtract(l_head, l_tail, r_head, r_tail, res_head, res_tail);
    }
    
    return add(l_head, l_tail, r_head, r_tail, res_head, res_tail);
    
}

int subtract(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){
    
    int neg_flag = 0;
    if (compare_lists(l_head, r_head) == -1) {
        Dlist *temp_h = l_head; l_head = r_head; r_head = temp_h;
        Dlist *temp_t = l_tail; l_tail = r_tail; r_tail = temp_t;
        neg_flag = 1; 
    }
    
    int borrow = 0, diff =0;
    while (l_tail != NULL || r_tail != NULL) {
        int num1 = (l_tail != NULL) ? l_tail->data : 0;
        int num2 = (r_tail != NULL) ? r_tail->data : 0;
    
        diff = num1 - num2 - borrow;
    
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
    
        if (dl_insert_first(res_head, res_tail, diff) == FAILURE) {
            return FAILURE;
        }
    
        if (l_tail != NULL) l_tail = l_tail->prev;
        if (r_tail != NULL) r_tail = r_tail->prev;
    }
    
    remove_leading_zeros(res_head,res_tail);
    
    
    (*res_head)->sign = neg_flag || l_head->sign;
    
    
    return SUCCESS;

}