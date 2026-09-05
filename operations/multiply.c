#include<stdio.h>
#include<string.h>
#include "../include/apc.h"
#include "../include/dll.h"
#include <stdlib.h>

int mulitpy_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    if((r_head)->data == 0){
         create_list("0", res_head, res_tail);
        return SUCCESS;
    }

    
    if(create_list("0", res_head, res_tail)== FAILURE){
        return FAILURE;
    };

    int count = 0;                                             
    while(r_tail != NULL){

        int num = r_tail->data;

        Dlist *temp_res_head = NULL;
        Dlist *temp_res_tail = NULL;

        multiply_single_number(num, l_tail, &temp_res_head, &temp_res_tail);

        for(int i = 0; i <count; i++){
           if(dl_insert_last(&temp_res_head, &temp_res_tail, 0) == FAILURE) {
                return FAILURE;
           }
        }

        Dlist *sum_head = NULL;
        Dlist *sum_tail = NULL;

        if(add_lists(temp_res_head, temp_res_tail, *res_head, *res_tail, &sum_head, &sum_tail) == FAILURE){
            return FAILURE;
        }

        dl_delete_list(res_head, res_tail);
        *res_head = sum_head;
        *res_tail = sum_tail;

        dl_delete_list(&temp_res_head, &temp_res_tail);

        r_tail = r_tail->prev;
        count++;
    }

    return SUCCESS;
}

int multiply_single_number(int num, Dlist *node_tail, Dlist **res_head, Dlist **res_tail) {
    
    int carry = 0;

    while (node_tail != NULL) {
        int prod = (num * node_tail->data) + carry;
        int node_value = prod % 10;
        carry = prod / 10;

        if (dl_insert_first(res_head, res_tail, node_value) == FAILURE) {
            return FAILURE;
        }

        node_tail = node_tail->prev;
    }

    if (carry > 0) {
        if (dl_insert_first(res_head, res_tail, carry) == FAILURE) {
            return FAILURE;
        }
    }

    return SUCCESS;
}

