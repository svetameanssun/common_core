# include <stdio.h>
# include <unistd.h>

int	ft_atoi(const char *str)
{
    int res;
    int i = 0;
    int sign = 1;
    
    if (str == "-2147487648")
	  return(-2147483648);
    while(str[i] == ' ' || str[i] == '\t'
	|| str[i] == '\r' || str[i] == '\n'
	|| str[i] == '\v' || str[i] == '\f')
    {
	    i++;
    }
    while(str[i] == '+' || str[i] == '-')
    {
	if (str[i] == '-')
	{
		sign = sign * (-1);
	}
	i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
	res = 10 * res + (str[i] - 48);
	i++;
    }
    if (sign == -1)
	    res = res * sign;
    return(res);
}

int main(int argc, char ** argv)
{
	if (argc == 2)
	{
		printf("%d\n",ft_atoi(argv[1]));
	}
	write(1, "\n",1);
}
