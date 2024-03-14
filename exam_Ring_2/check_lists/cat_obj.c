#include "cat_struct.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*-----------------------------------------------------------------------------
    Asigning age both  to the dog and cat
    -----------------------------------------------------------------------------*/
    type_c new_cat;
    type_d new_dog;
    type_c *ptr_cat;
    type_d *ptr_dog;

    /*-----------------------------------------------------------------------------
    Asigning age both to new_dog and new_cat
    -----------------------------------------------------------------------------*/
    new_cat.age = 3;
    new_dog.age = 5;

    /*-----------------------------------------------------------------------------
    Asigning age both to ptr_dog and prt_cat
    -----------------------------------------------------------------------------*/
    ptr_cat = malloc(sizeof(type_c));// We need to malloc the ptr_cat FIRST,
    ptr_dog = malloc(sizeof(type_d));// to anything inside!
    ptr_cat -> age = 4;
    ptr_dog -> age = 6;

    /*-----------------------------------------------------------------------------
    Asigning a name to the new_cat
    -----------------------------------------------------------------------------*/
    //char *cat_name = malloc(10); //USELESS TO DO MALLOC HERE!
    char *cat_name = "Vasylisa";
    //cat_name[3] = 'Y'; //IMPOSIBLE T DO IT HERE!!
    new_cat.name = cat_name; //1)
    //2)while -- new_cat.name[i] = cat_name[i]; - WRONG!
    //new_cat.name[3] = 'Y';'Y'; //IMPOSIBLE T DO IT HERE!!

    /*-----------------------------------------------------------------------------
    Asigning a name to the ptr_cat
    -----------------------------------------------------------------------------*/
    ptr_cat -> name = "Blair";
    
    /*-----------------------------------------------------------------------------
    Asigning a name to the new_dog
    -----------------------------------------------------------------------------*/
    char dog_name[10] = "Archibald";
    int i = 0;
    while(i < 10)
    {
        new_dog.name[i] = dog_name[i];
        i++;
    }
    new_dog.name[i] = '\0';

    /*-----------------------------------------------------------------------------
    Asigning a name to *ptr_dog
    -----------------------------------------------------------------------------*/
    char ptr_dog_name[6] = "Dusia";
    i = 0;
    while(i < 6)
    {
        ptr_dog -> name[i] = ptr_dog_name[i];
        i++;
    }
    ptr_dog -> name[i] = '\0';
    
    /*-----------------------------------------------------------------------------
    Asigning a color to new_cat
    -----------------------------------------------------------------------------*/
    char *cat_color = "Black";// in this case cat1_color become sa static adress
    // but we still can assign this static adress to the pointer(dynamic adress) cat1.color
    //cat_color[2] = 'A'; //IMPOSIBLE T DO IT HERE!!
    new_cat.color = cat_color;
    //cat1_color = cat1.color  - IMPOSSIBLE TO DO!


    /*-----------------------------------------------------------------------------
    Asigning a color to *ptr_cat
    -----------------------------------------------------------------------------*/
    ptr_cat ->color = "Purple";

    /*-----------------------------------------------------------------------------
    Asigning a color to new_dog
    -----------------------------------------------------------------------------*/
    char dog_color[12] = "White";
    dog_color[3] = 'T';
    //dog1.color  = dog1_color; - WE CANNOT DO THIS!!!
    // because char str[] has the static address,
    // and with this action we are saying that we want dog1.color to have
    // the new adress of dog1_color
    i = 0;
    while(i < 5)
    {
        new_dog.color[i] = dog_color[i];
        i++;
    }
    new_dog.color[i] = '\0';


    /*-----------------------------------------------------------------------------
    Asigning a color to *ptr_dog
    -----------------------------------------------------------------------------*/
    char ptr_dog_color[12] = "White";
    ptr_dog_color[3] = 'T';
    i = 0;
    while(i < 5)
    {
        ptr_dog->color[i] = ptr_dog_color[i];
        i++;
    }
    ptr_dog -> name[i] = '\0';
    //-----------------------------------------------------------------------------
    
    printf("new_cat.age - %i\n", new_cat.age);
    printf("new_dog.age - %i\n", new_dog.age);
    printf("ptr_cat->age - %i\n", ptr_cat->age);
    printf("ptr_dog->age - %i\n", ptr_dog->age);
    printf("\n");

    
    printf("new_cat.name - %s\n", new_cat.name);
    printf("new_dog.name - %s\n", new_dog.name);
    printf("ptr_cat->name - %s\n", ptr_cat->name);
    printf("ptr_dog->name - %s\n", ptr_dog->name);
    printf("\n");

    
    printf("new_cat.color - %s\n", new_cat.color);
    printf("new_dog.colot - %s\n", new_dog.color);
    printf("ptr_cat->color - %s\n", ptr_cat->color);
    printf("ptr_cat->color %s\n", ptr_dog->color);
    printf("\n");
    

    return (0);
}