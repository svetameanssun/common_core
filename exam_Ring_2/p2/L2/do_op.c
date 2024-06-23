# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
    {
        len++;
    }
    return(len);
}


int ft_atoi(char *str)
{
    int sign = 1;
    int nbr = 0;
    int i = 0;
    int str_len = ft_strlen(str);

    if (str[0] == '-')
    {
        sign = -1;
        i++;
    }
    
    while(i < str_len)
    {
        nbr = 10 * nbr + (str[i] - '0'); 
        i++;
    }
    nbr*=sign;
    return(nbr);
}

void do_op(char *num1, char *op, char *num2)
{
    int n1 = ft_atoi(num1);
    int n2 = ft_atoi(num2);

    if (op[0] == '*')
        printf("%d\n", n1 * n2);
    if (op[0] == '/')
        printf("%d\n",n1 / n2);
    if (op[0] == '+')
        printf("%d\n",n1 + n2);
    if (op[0]== '-')
        printf("%d\n",n1 - n2);
    if (op[0] == '%')
        printf("%d\n",n1 % n2);

}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        do_op(argv[1], argv[2], argv[3]);
    }
    else
        write(1,"\n",1);
}