# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int fprime(char *str)
{
    int i;
    int number;
    
    if(str[0] == '-')
    {
        return(0);
    }

    i = 1;
    number = atoi(str);

    if(number == 1)
    {
        printf("1");
    }
    i++;
    while(number >= i)
    {
        if(number%i == 0)
        {
            printf("%d", i);
            if(number == i)
            {
                return(0);
            }
            printf("*");
            number /= i;
            i = 1;
        }
        i++;

    }
    return (1);
}

int main(int argc, char ** argv)
{
    if (argc  == 2)
    {
        fprime(argv[1]);
    }
    printf("\n");
    return(0);

}