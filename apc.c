#include<stdio.h>
#include<string.h>
#include"dll.h"
#include"apc.h"
#include <stdlib.h>

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

    if (compare_lists(l_head, r_head) == -1) {
        Dlist *temp_h = l_head; l_head = r_head; r_head = temp_h;
        Dlist *temp_t = l_tail; l_tail = r_tail; r_tail = temp_t;
        neg_flag = 1; 
    }

    int borrow = 0;
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
    
    if (neg_flag && *res_head != NULL) {
    (*res_head)->data = -((*res_head)->data);
    }

    remove_leading_zeros(res_head,res_tail);

    return SUCCESS;
    
}

int compare_lists(Dlist *l_head, Dlist *r_head) {
    int len1 = 0, len2 = 0;
    Dlist *l_temp = l_head, *r_temp = r_head;

    while (l_temp != NULL) { len1++; l_temp = l_temp->next; }
    while (r_temp != NULL) { len2++; r_temp = r_temp->next; }

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    l_temp = l_head;
    r_temp = r_head;

    while (l_temp && r_temp) {
        if (l_temp->data > r_temp->data) return 1;
        if (r_temp->data > l_temp->data) return -1;
        l_temp = l_temp->next;
        r_temp = r_temp->next;
    }

    return 0;
}


int divide_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){


    if((r_head)->data == 0){
        printf("Invalid input !\n");
        return FAILURE;
    }

    int comp = compare_lists(l_head, r_head);
    if(comp == -1){
        create_list("0", res_head, res_tail);
        return SUCCESS;
    }
    else if(comp == 0){
        create_list("1", res_head, res_tail);
        return SUCCESS;
        
    }
    
    Dlist *out_l_head = l_head;
    Dlist *out_l_tail = l_tail;
    
    int count = 0;

    while( compare_lists(out_l_head, r_head) >= 0){

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

int mulitpy_lists(Dlist *l_head, Dlist *l_tail, Dlist *r_head, Dlist *r_tail,Dlist **res_head, Dlist **res_tail){

    if((r_head)->data == 0){
         create_list("0", res_head, res_tail);
        return SUCCESS;
    }


}

void remove_leading_zeros(Dlist **head, Dlist **tail) {
    while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL) {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
