/* -----------------------------------------------------------------------------------------
Author Name : Asfaq Moideen
Description : Arbitrary Precision Calculator (APC)
--------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<string.h>
#include "../include/apc.h"
#include "../include/dll.h"
#include <stdlib.h>

int divide_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){


    if((r_head)->data == 0){
        printf("Invalid input !\n");
        return FAILURE;
    }

    int comp = compare_lists(l_head, r_head);
    if(comp == -1){
        create_list("0", res_head, res_tail);
        printf("Invalid input !\n");
        return FAILURE;
    }
    else if(comp == 0){
        create_list("1", res_head, res_tail);
        return SUCCESS;
        
    }
    
    Dlist *out_l_head = l_head;
    Dlist *out_l_tail = l_tail;
    
    int count = 0;

    while(compare_lists(out_l_head, r_head) >= 0){

        Dlist *out_res_head = NULL , *out_res_tail = NULL;

        subtract_lists(out_l_head, out_l_tail, r_head, r_tail, &out_res_head, &out_res_tail);

        out_l_head = out_res_head;
        out_l_tail = out_res_tail;

        count++;
    }

    while (count > 0) {
        dl_insert_first(res_head, res_tail, count % 10);
        count /= 10;
    }

    return SUCCESS;
}