/* -----------------------------------------------------------------------------------------
Author Name : Asfaq Moideen
Description : Arbitrary Precision Calculator (APC)
--------------------------------------------------------------------------------------------*/

#include "../include/dll.h"
#include<stdio.h>
#include<stdlib.h>

int dl_insert_first(Dlist **head, Dlist **tail, int data)
{   
    
    Dlist *new_node = malloc(sizeof(Dlist));
    if(new_node == NULL){
        printf("Memory allocation failure");
        return FAILURE;
    }
    
    new_node->data = data;
    new_node->prev = NULL;
    
    if(*head == NULL){
        
        *head = new_node;
        *tail = new_node;
        new_node->next = NULL;
        return SUCCESS;
    }
    
    
    new_node->next = *head;
    
    (*head)->prev = new_node;
    
    *head = new_node;
    
    return SUCCESS;
    
}

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = malloc(sizeof(Dlist));
    if(new_node == NULL){
        return FAILURE;
    }
    
    new_node->data = data;
    new_node->next = NULL;
    
    //0 element
    if(*head == NULL){
        *head = new_node;
        *tail = new_node;
        new_node->prev = NULL;
        return SUCCESS;
    }
    
    //else
    new_node->prev = *tail;
    (*tail)->next = new_node;
    *tail = new_node;
    
    return SUCCESS;
}

void print_list(Dlist *head)
{   
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }

    }

    printf("\n");
}

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL) {
            return FAILURE;
        }

        while ((*head)->next != NULL) {
            *head = (*head)->next; 
            free((*head)->prev);   
        }

        free(*head);

        *head = NULL;
        *tail = NULL;

        return SUCCESS;
}