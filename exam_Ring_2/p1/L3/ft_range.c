# include <unistd.h>
# include <stdlib.h>

int ft_abs(int number)
{
    if (number < 0)
        return(number * -1);
    else
        return(number);
}

int     *ft_range(int start, int end)
{
    int *arr;
    int size = ft_abs(start - end);
    arr = malloc((size + 1) * 4);
    int i = 0;
    
    int inc = 1;
    if(start > end)
    {
        inc = -1;
    }
    while(start !=  end)
    {
        arr[i] = start;
        start = start + inc;
        i++;
    }
    arr[i] = start;
    return(arr);
}

int main()
{
    int *arr = ft_range(1,5);
    int i = 0;
    char temp;
    while(i < 5)
    {
        temp = arr[i] + 48;
        write(1, &temp, 1);
        i++;
    }
}