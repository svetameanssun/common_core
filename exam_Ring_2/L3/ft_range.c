# include <unistd.h>
# include <stdlib.h>

int     *ft_range(int start, int end)
{
    int *arr;
    int size;
    int i;

    size = 1;
    i = 0;
    if (start < end)
    {
        while(start + size <= end)
        {
            size++;
        }
        arr = malloc(size * 4);
        while(start + i <= end)
        {
            arr[i] = start + i;
            i++;
        }
    
    }
    else if(start > end)
    {
        while(end + size < start)
        {
            size++;
        }
        arr = malloc(size * 4);
        while(start - i >= end)
        {
            arr[i] = start - i;
            i++;
        }
    }
    else
    {
        arr = malloc(4);  
        arr[0] = start;
    }
    return(arr);
}

int main()
{
    int *arr = ft_range(1,5);
    int i = 0;
    char temp;
    while(i < 10)
    {
        temp = arr[i] + 48;
        write(1, &temp, 1);
        i++;
    }
}