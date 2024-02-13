# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j= 0;
    int temp;

    while(i < (size -1))
    {
        
        while( j < (size-1-i))
        {
            if(*(tab +j) > *(tab + j +1))
            {
                temp = *(tab + j);
                *(tab + j) =  *(tab + j +1);
                *(tab + j +1)  = temp;
            }
            j++;
        }
        j = 0;
        i++;

    }

}

int main()
{
    int * tab;
    tab = malloc(sizeof(int) * 5);
    tab[0] = 12;
    tab[1] = 121;
    tab[2] = -12;
    tab[3] = 2;
    tab[4] = 1;

    int t = 0;
    sort_int_tab(tab,5);
    while(t < 5)
    {
        printf("%i\n",tab[t]);
        t++;
    }
}