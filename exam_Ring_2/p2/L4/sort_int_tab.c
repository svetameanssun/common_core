#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.*/

void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int swap = 0;
    while(i < size - 1)
    {
        if(tab[i] > tab[i + 1])
        {
            swap = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = swap;
            i = 0;
        }
        else
            i++;

    }


}

int main()
{
    int tab[6] = {4, 12, 333, 0, 1212, 2};
    sort_int_tab(tab, 6);
    int i = 0;
    while(i < 6)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    
}