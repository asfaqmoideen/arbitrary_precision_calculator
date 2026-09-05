#include<stdio.h>
#include<string.h>
#include "include/apc.h"
#include "include/dll.h"

int main(int argc, char *argv[]){

    if(argc < 4){
        printf("*********** APC ************\n");
        printf("Input format 'Operand 1' 'Operator' 'Operator 2'\n");
        printf("Example : 123413242 + 24123411234\n");
        printf("Operators - '+' , '-', '*', '/'\n");
        return -1;
    }   

    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/') {
        printf("Only '+', '-', '*', '/', are operated\n");
        return -1;
    }

    
    Dlist *l_head = NULL, *l_tail = NULL, *r_head=NULL, *r_tail=NULL, *res_head = NULL, *res_tail = NULL;

    // creating linked lists from the user input
    if(create_list(argv[1], &l_head, &l_tail) == FAILURE){
        printf("Memory allocation failure");
        return -1;
    }

    if(create_list(argv[3], &r_head, &r_tail) == FAILURE){
        printf("Memory allocation failure\n");
        return -1;
    }
    
    // selecting the operation based on user's input arg. 
    switch (argv[2][0])
    {
        case '+':
        if(add_lists(l_head, l_tail, r_head, r_tail, &res_head, &res_tail) == FAILURE){
            printf("Memory allocation failure\n");
            return -1;
        };
        break;
        case '-':
        if(subtract_lists(l_head, l_tail, r_head, r_tail, &res_head, &res_tail) == FAILURE){
            printf("Memory allocation failure\n");
            return -1;
        };
        break;
        case '*':
        if(mulitpy_lists(l_head, l_tail, r_head, r_tail, &res_head, &res_tail) == FAILURE){
            printf("Failed to perform operation\n");
            return -1;
        };
        break;
        case '/':
        if(divide_lists(l_head, l_tail, r_head, r_tail, &res_head, &res_tail) == FAILURE){
            printf("Failed to perform operation\n");
            return -1;
        };
        break;
    }  
    
    print_list(res_head);

    // frees the memory upon successfull operation
    dl_delete_list(&l_head, &l_tail);
    dl_delete_list(&r_head, &r_tail);
    dl_delete_list(&res_head,&res_tail );
    return 0;
}