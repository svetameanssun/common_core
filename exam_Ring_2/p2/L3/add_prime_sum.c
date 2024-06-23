# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int lil_atoi(char *str)
{
    int res = 0;
    int i = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = 10 * res + (str[i] - '0');
        i++;
    }
    return(res);
}

int is_prime(int num)
{
    int coef = 2;
    if(num<= 1)
        return(0);
    while(coef*coef<=num)
    {
        if(num % coef == 0)
            return(0);
        coef++;
    }
    return(1);
}

void ft_putnbr(int num)
{
    int c;

    if(num > 9)
        ft_putnbr(num/10);
    c = num%10 + '0';
    write(1, &c, 1);
}

int add_prime_sum(char *str_num)
{
    int num = lil_atoi(str_num);
    int i = 2;
    int sum = 0;
    while(i <= num)
    {
        if (is_prime(i) == 1)
            sum = sum + i;
        i++;
    }
    
    return(sum);

}



int main (int argc, char **argv)
{
    if (argc == 2)
    {
        int res = add_prime_sum(argv[1]);
        ft_putnbr(res);
    }
    else
        write(1, "0", 1);
    write(1,"\n", 1);
    return (0);
}