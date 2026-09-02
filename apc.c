#include<stdio.h>
#include<string.h>
#include"dll.h"

int create_list(char *input, Dlist **head, Dlist **tail){

    int len = strlen(input);
    while (*input == '0' && *(input + 1) != '\0') {
        input++;
    }

    while (*input != '\0') {
        int n = *input - '0'; 

        if (dl_insert_last(head, tail, n) == FAILURE) {
            printf("Memory Allocation Failure\n");
            return FAILURE;
        }
        input++;
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

int subtract_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    int diff = 0, neg_flag = 0;
    while (l_tail != NULL || r_tail != NULL)
    {   
        int num1 = l_tail == NULL ? 0 : l_tail->data;
        int num2 = r_tail == NULL ? 0 : r_tail->data;


        if(num1 < num2){

            if(l_tail->prev != NULL){
                l_tail->prev->data--;
                num1+=10;
            }
            else{
                int temp = num2;
                num2 = num1;
                num1 = temp;
                neg_flag = 1;
            }
        }

        printf("num1 : %d num2 %d ", num1, num2);
        diff = num1 - num2;
        printf("Diff : %d\n", diff);
        if(neg_flag) diff = -diff;
        if(dl_insert_first(res_head,res_tail, diff) == FAILURE){
            printf("Memory allocation failure");
            return FAILURE;
        }
        
        if (l_tail != NULL) l_tail = l_tail->prev;
        if (r_tail != NULL) r_tail = r_tail->prev;

    }

    return SUCCESS;
    
}
