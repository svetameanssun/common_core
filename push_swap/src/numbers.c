#include "push_swap.h"

long	ft_atol(char *str)
{
	long res;
	int	sign;

	res = 0;
	sign = 1;
	/*if (equal_str(str, "-2147483648"))
		return(-2147483648);*/
	if (*str == '-')
	{
		sign = sign * (-1);
		str++;
	}
	if (*str == '+')
		str++;
	while (*str && *str != ' ')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}
