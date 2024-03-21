#include "phonebook.h"

static int input()
{
    int choice;
    printf("Welcome to PHONEBOOK\nTo add new number  - introduce 1\nTo exit - intoduce 0\n");

    scanf("%d", &choice);

    if (choice == 1)
        printf("new_number\n");
    else if (choice == 0)
        printf("exit\n");
    else
        printf("Incorrect input. Try again\n");
    return(1);
}
int main()
{
    input();
    return (1);
}