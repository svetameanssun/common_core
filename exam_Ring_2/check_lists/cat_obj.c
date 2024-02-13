#include "cat_struct.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    type_c cat1;
    cat1.age = 3;
    type_d dog1;
    dog1.age = 5;

    printf("%i\n", cat1.age);
    printf("%i\n", dog1.age);

    char dog1_name[10] = "Archibald";
    int i = 0;
    while(i < 10)
    {
        dog1.name[i] = dog1_name[i];
        i++;
    }
    cat1.name = malloc(sizeof(char) * (8 + 1));
    char cat1_name[10] = "Vasilysa";
    i=0;
    while(i < 8)
    {
        cat1.name[i] = cat1_name[i];
        i++;
    }
    printf("%s\n", dog1.name);
    printf("%s\n", cat1.name);
    return (0);
}