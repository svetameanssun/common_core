# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int ft_abs(int number)
{
    if (number < 0)
        return (number * -1);
    else
        return(number); 
}

int     *ft_rrange(int start, int end)
{
    int size = ft_abs(end - start);
    int *arr = malloc (4 *(size + 1));

    printf("%i", size);
    
    int inc = 1;
    int i = 0;
    if (end > start)
    {
        inc = -1;
    }
    while(end!= start)
    {
        arr[i] = end;
        //char temp = arr[i] + 48;
        //write(1, &temp,1);
        end = end + inc;
        i++;
    }
    arr[i] = start;
    return(arr);

}
int main()
{
    int *arr = ft_rrange(1,5);
    int i = 0;
    while(i < 5)
    {
        printf("%i", arr[i]);
        i++;
    }

}