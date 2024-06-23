# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int size = 1;
    int pass = 1;
    int i = 0;
    int * arr;
    if(start > end)
        pass = -1;
    while(start != end)
    {
        start+= pass;
        size++;
    }
    arr = (int *)malloc(sizeof(int) * size);
    pass *= -1;
    while(i < size)
    {
        arr[i] = end;
        end+=pass;
        i++;
    }
    printf("%d\n",size); 
    return(arr);
}

int main()
{
    int *arr = ft_rrange(-2, 3);
    int i = 0;
    while(i < 6)
    {
        printf("%d ", arr[i]);
        i++;
    }
}