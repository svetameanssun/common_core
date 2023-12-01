#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return(a + b);
}
//The function "function" does not work right, because:
// -- address of stack memory associated with local variable 'array' returned

int *function(void)
{
    static int static_res = 0;// we have to define static variable
    // right after initializing it, not in another line!
   static_res = sum(static_res, 2);

    int not_static_res = 0;
    not_static_res = sum(not_static_res,2);
    //printf("AAAA%i\n", not_static_res);
    int *array;
    array = malloc(2 * sizeof(int));
    array[0] = static_res;
    array[1] =  not_static_res;
    return(array);
} 
int main(void)
{
    int *array_res;
    int i;

    i = 0;
    while(i < 10)
    {
        
        array_res = function();
        printf("not_static result: %i\n", array_res[1]);
        printf("static result: %i\n",array_res[0]);
        printf("\n");
        i++;
    }
    return (0);

    
}



