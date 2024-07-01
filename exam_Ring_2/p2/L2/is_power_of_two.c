/*Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:*/
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	    is_power_of_2(unsigned int n)
{
    if(n == 0)
        return(0);
    while(n != 2)
    {
        if(n%2!= 0)
        {
            return(0);
        }
        n= n/2;
    }
    return(1);
}

int main()
{
    
    int res;
    unsigned int i = 0;
    while(i <= 8192)
    {
        res = is_power_of_2(i);
        if (res == 1)
            printf("\npower of 2: %d\n", i);
        i++;
    }
}