#include<stdio.h>
#include<string.h>
#include "../include/apc.h"
#include "../include/dll.h"
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

void remove_leading_zeros(Dlist **head, Dlist **tail) {
    while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL) {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}