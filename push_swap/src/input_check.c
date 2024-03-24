#include "push_swap.h"


int	longs_unique(long *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] > MAX || arr[i] < MIN)
		{
			return(0);
		}
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

int	input_valid_str(char *str)
{
	int	i;
	
	i = 0;
	if (!str[i] || str[i] == 32)
	{
		return (0);
	}
	while (str[i] && str[i+1])
	{
		if (is_digit(str[i]))
			i++;
		else
		{
			if ((plus_or_minus(str[i])) && is_digit(str[i + 1])
				&& (i == 0 || str[i - 1] == ' '))
				i++;
			else if (is_space(str[i]) && (is_digit(str[i + 1])
					|| plus_or_minus(str[i + 1])) && is_digit(str[i - 1]))
				i++;
			else
			{
				return (0);
			}
		}
	}
	return (i);
}

int	input_valid_word(char *str)
{
	int i;

	i = 0;
	if (!str[i] || str[i] == 32)
		return (0);
	while(str[i])
	{
		if(plus_or_minus(str[i]))
		{
			i++;
		}
		if(is_digit(str[i]))
		{
			i++;
		}
		else
			return(0);
	}
	if((plus_or_minus(str[0])) && i == 1)
		return(0);
	return(i);
}

