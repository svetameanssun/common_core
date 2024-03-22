#include "push_swap.h"

int ft_error()
{
	write(1, "error\n", 6);
	exit(0);
}
int	longs_unique(long *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] > MAX || arr[i] < MIN)
			return(0);
		j = 0;
		while (j < len)
		{
			if (arr[i] == arr[j] && i != j)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	input_valid(char *str)
{
	int	i;
	
	i = 0;
	if (!str[i] || str[i] == 32)
		return (0);
	while (str[i] && str[i+1])
	{
		if (is_digit(str[i]))
			i++;
		else
		{
			if ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1])
				&& (i == 0 || str[i - 1] == ' '))
				i++;
			else if (str[i] == ' ' && (is_digit(str[i + 1])
					|| str[i + 1] == '-' || str[i + 1] == '+') && is_digit(str[i - 1]))
				i++;
			else
				return (0);
		}
	}
	return (i);
}

