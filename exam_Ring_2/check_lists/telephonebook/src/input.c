#include "phonebook.h"

int main(int argc, char **argv)
{
    printf("Welcome to PHONEBOOK\nTo add new number  - introduce 1\nTo exit - intoduce 0\n");
}

int run(int argc, char **argv)
{
    
    if(argc == 2)
    {
        if (argv[1][0] == '1' && argv[1][1] == '\n')
            printf("new_number\n");
        else if (argv[1][0] == '0' && argv[1][1] == '\n')
            printf("exit\n");
        else
            printf("Incorrect input. Try again\n");
    }
    else
        printf("Wrong input. Try again\n");
}