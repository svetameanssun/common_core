#include <stdlib.h>
#include <stdio.h>

//Constant Pointers

/* In constant pointers, the memory address stored inside the pointer
is constant and cannot be modified once it is defined.
It will always point to the same memory address.*/

/*int main()
{

    char * const ptr = malloc(sizeof(char)*7);
    //ptr = malloc(sizeof(char)*7); We cannot redefine the constant pointer
    //even with the same value;
    int i = 0;
    while(i < 7)
    {
        *(ptr + i) = 'c';
        i++;
    }
    ptr[i] = '\0';
    printf("%s", ptr);


}*/

//Pointer to Constant

/*The pointers pointing to a constant value
that cannot be modified are called pointers to a constant.
Here we can only access the data pointed by the pointer,
but cannot modify it. Although, we can change the address
stored in the pointer to constant.*/

/*int main()
{
    const char * ptr = "hola";

    //we cannot change the value that
    //is pointer by the pointer
    //*ptr = 'b'; - !NO
    // ptr[0] =  'b'; - !NO

    //but we can change the pointer!
    char *ptr_changed = "adios";
    ptr = ptr_changed;

    printf("%s", ptr);

}*/