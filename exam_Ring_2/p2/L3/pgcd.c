# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

void ft_putnbr(int n)
{
    int c;
    if(n > 9)
        ft_putnbr(n/10);
    c = n%10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    if (str == "-2147483648")
        return(-2147483648);
    while(str[i] == ' ')
    {
        i++;
    }
    while(str[i] == '+' || str[i] == '-')
    {
        if(str[i] == '-')
            sign*=-1;
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = 10 * res + (str[i] - '0');
        i++;
    }
    res *= sign;
    return(res);
}

void pgcd(char *s1, char * s2)
{
    int n1 = ft_atoi(s1);
    int n2 = ft_atoi(s2);
    if (n1 > 0 && n2 > 0)
    {
        while(n1 != n2)
        {
            if(n1 > n2)
                n1 = n1 - n2;
            else
                n2 = n2 - n1;
        }
        ft_putnbr(n1);
    }
    /*int i = 2;
    int res;
    if(n1 > n2)
        res = n2;
    if(n1 < n2)
        res = n1;
    while(res - 1 > i)
    {
        if(n1%res == 0 && n2%res == 0)
            return(res);
        res--;
    }
    return(1);*/
}

int main(int argc, char ** argv)
{
   
    if (argc == 3)
        pgcd(argv[1], argv[2]);
    write(1, "\n", 1);


}