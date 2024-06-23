# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int abs(int num)
{
    if (num < 0)
        return(num * (-1));
    return(num);
}

int     *ft_range(int start, int end)
{
    int *arr;
    int count = 1;
    int pass = 1;
    int i = 0;
    if (end > start)
        pass = -1;
    
    while(end!=start)
    {
        end += pass;
        count++;
    }
    pass *= -1;

    arr = (int*)malloc(sizeof(int)*count);
    while(i < count)
    {
        arr[i] = start;
        start += pass;
        i++;
    }

    printf("%d\n", count);
    return(arr);
}

int main()
{
    int *arr = ft_range(0, 0);
    int i = 0;
    while(i < 1)
    {
        printf("%d ", arr[i]);
        i++;
    }
}