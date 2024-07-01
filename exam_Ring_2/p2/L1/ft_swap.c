/*Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:*/
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}

int main()
{
    int a = 111;
    int b = 0;
    ft_swap(&a, &b);
    printf("%d and %d", a, b);
}

