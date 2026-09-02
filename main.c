#include "apc.h"
#include<stdio.h>
#include<string.h>
#include"dll.h"

int main(int argc, char *argv[]){

    if(argc < 4){
        printf("*********** APC ************\n");
        printf("Input format 'Operand 1' 'Operator' 'Operator 2'\n");
        printf("Example : 123413242 + 24123411234\n");
        printf("Operators - '+' , '-', '*', '%%'\n");
        return -1;
    }   

    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' && argv[2][0] != '/') {
        printf("Only '+', '-', '*', '/', are operated\n");
        return -1;
    }

    
    Dlist *l_head, *l_tail, *r_head, *r_tail, *res_head, *res_tail;
    printf("The input arguments are correct !\n");
    create_list(argv[1], &l_head, &l_tail);
    create_list(argv[3], &r_head, &r_tail);

    printf("Left : ");
    print_list(l_head);
    printf("Right : ");
    print_list(r_head);
    
    printf("Let me try to ");

    switch (argv[2][0])
    {
        case '+':
        printf("Add !\n");
        add_lists(l_head, l_tail, r_head, r_tail, &res_head, &res_tail);
        break;
        // case '-':
        // printf("Subtract !\n");
        // result = subtract_lists(l_operand, r_operand);
        // break;
        // case '*':
        // result = multiply_lists(l_operand, r_operand);
        // break;
        // case '/':
        // result = divide_lists(l_operand, r_operand);
        // break;
        
        default:
        break;
    }  
    
    
    print_list(r_head);
    return 0;
}