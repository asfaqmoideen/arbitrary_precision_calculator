#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{

	Slist* newNode = malloc(sizeof(Slist));
   
    if(newNode == NULL){
        return FAILURE;
    }
    newNode->data = data;

    if(*head == NULL){
       *head = newNode;
       return SUCCESS;
    }

    newNode->link = *head;

    *head = newNode;

    return SUCCESS;
}

int insert_at_last(Slist **head, data_t data)
{
   Slist* newNode = malloc(sizeof(Slist));
   
    if(newNode == NULL){
        return FAILURE;
    }
    newNode->data = data;
    newNode->link = NULL;

   if(*head == NULL){
       *head = newNode;
       return SUCCESS;
    }
    
    Slist *node = *head;
    while(node->link != NULL){
        node = node->link;
    }
    node->link = newNode;
    return SUCCESS;
}

int insert_before(Slist **head, int gdata, int n_data){

    if(*head == NULL){
        return FAILURE;
    }

    Slist *temp = *head;
    while(temp->link->link != NULL){
        if(temp->link->data == gdata){

            Slist* new_node = malloc(sizeof(Slist));
            if(new_node == NULL) return FAILURE;

            new_node->link = temp->link;
            new_node->data = n_data;
            temp->link = new_node;
            return SUCCESS;

        }
        temp = temp->link;
    }

}

void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%d", head -> data);
		    head = head -> link;
	    }
    }

    printf("\n");
}