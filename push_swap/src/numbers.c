#include "push_swap.h"

int ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return(num);
}

long	ft_atol(char *str)
{
	long res;
	int	sign;

	res = 0;
	sign = 1;
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

int stack_contents_mean(t_stack ** stck)
{
	long divident;
	int divisor;

	t_stack * temp_stck;

	divident = 0;
	divisor = 1;
	temp_stck = *stck;
	while(temp_stck)
	{
		divident += temp_stck->content;
		divisor++;
		temp_stck = temp_stck->next;
	}
	return(divident/divisor);

}
