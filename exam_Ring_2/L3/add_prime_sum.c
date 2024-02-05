# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int ft_atoi(char * str)
{
    int i = 0;
    int res = 0;
    while(str[i] != '\0')
    {
        res = res * 10 +  (str[i] - 48);
        i++;
    }
    return(res);
}

int is_prime(int num)
{
    int i = 2;

    if (num <= 1)
        return (0);
    while(i * i <= num)
    {
        if(num % i == 0)
            return(0);
        i++;
    }
    return(1);
}

/*void ft_write_number(int number){
    char str[10] = "0123456789";

    if (number > 9)
    {
        ft_write_number(number/10);
    }
    write(1, &str[number % 10],1);
}*/

void ft_putnbr(int n)
{
    if (n >= 10)
    {
        ft_putnbr(n/10);
    }
    char digit = n%10 + '0';
    write(1, &digit,1);
}

void add_prime_sum(char *str)
{
    int nbr = ft_atoi(str);
    int sum = 0;
    while(nbr > 0)
    {
        if (is_prime(nbr))
        {
            sum += nbr;
        }
        nbr--;
    }
    ft_putnbr(sum);
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        add_prime_sum(argv[1]);
    }
    else
    {
        write(1, "0", 1);
    }
    write(1,"\n", 1);
}