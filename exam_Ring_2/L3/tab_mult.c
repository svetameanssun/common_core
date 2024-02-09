# include <unistd.h>

int ft_atoi(char *str)
{
    int i = 0;
    char num;
    while(str[i])
    {
        num = num * 10 + str[i] - '0';
        i++;
    }
    return(num);
}
int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return(i);
}

void ft_putnbr(int nbr)
{
    while(nbr >= 10)
    {
        ft_putnbr(nbr / 10);
    }
    char digit = nbr + '0';
    write(1, &digit, 1);
}

void tab_mult(char *str)
{
    int i = 1;
    int num = ft_atoi(str);
    int res;
    char c;
    int str_len = ft_strlen(str);
    while(i <= 10)
    {
        c = i + 48;
        write(1, &c, 1);
        write(1, " x ", 3);
        write(1, str, str_len);
        write(1, " = ", 3);
        res = num * i;
        ft_putnbr(res);
        i++;
    }

}


int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        tab_mult(argv[1]);
    }
    write(1, "\n", 1);
}