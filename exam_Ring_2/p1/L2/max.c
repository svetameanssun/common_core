# include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int max;
    if (!tab)
    {
        return (0);
    }
    int i = 0;
    max = tab[i];
    while( i < len-1)
    {
        if(max < tab[i + 1])
        {
            max = tab[i + 1];
        } 
        i++; 
    }
    return (max);
}
int main()
{
    int arr[6] = {-22, 8, 60, 7, -1110, 0};
    printf("%i", max(arr,6));

}