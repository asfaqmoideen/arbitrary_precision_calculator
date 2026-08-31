#include "sll.h"
#include "apc.h"
#include<stdio.h>
#include<string.h>

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

    
    printf("The input arguments are correct !\n");
    Slist * l_operand = create_list(argv[1]);
    Slist * r_operand = create_list(argv[3]);

    printf("Left : ");
    print_list(l_operand);
    printf("Right : ");
    print_list(r_operand);
    
    printf("Let me try to ");

    Slist *result = NULL;
    switch (argv[2][0])
    {
        case '+':
        printf("Add !\n");
        result = add_lists(l_operand,r_operand);
        break;
        case '-':
        printf("Subtract !\n");
        result = subtract_lists(l_operand, r_operand);
        break;
        case '*':
        result = multiply_lists(l_operand, r_operand);
        break;
        case '/':
        result = divide_lists(l_operand, r_operand);
        break;

        default:
        break;
    }  
    
    if(result == NULL){
        printf("Failed to perform the operation");
    }

    print_list(result);
    return 0;
}