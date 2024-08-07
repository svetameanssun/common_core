/*Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/
#include <stdio.h>
#include <unistd.h>

void ft_putnbr(int num)
{
    int c;
    if(num > 9)
        ft_putnbr(num/10);
    c = num%10 + '0';
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == ' ')
    {
        i++;
    }
    while (str[i] == '-' || str[i] == '+')
    {       
        if (str[i] == '-')
           sign *= -1;
        i++;
    }
    while(str[i])
    {
        res = 10 * res + str[i] - '0';
        i++;
    }
    res *= sign;
    return(res);
}


void tab_mult(char *str)
{
    int num = ft_atoi(str);
    int i = 1;
    int res;
    //1 x 19 = 19
    while(i < 10)
    {
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(num);
        write(1, " = ", 3);
        res = i * num;
        ft_putnbr(res);
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        tab_mult(argv[1]);
    }
    else
        write(1, "\n", 1);
}