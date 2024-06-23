# include <unistd.h>
# include<stdio.h>
# include <stdlib.h>

int	    is_power_of_2(unsigned int n)
{
    if (n == 0)
    {
        return(0);
    }
    while(n != 1)
    {
        if(n % 2 != 0)
        {
            return (0);
        }
        n = n / 2;
    }
    return (1);
}

int main(int count, char ** vector)
{
    if (count == 2)
    {
        printf("%i",is_power_of_2(atoi(vector[1])));
    }
    write(1, "\n" ,1);
}
