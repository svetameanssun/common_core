#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int is_space(int c)
{
	return(c == ' ');
}

int end_or_space(int c)
{
	if(is_space(c))
		return(c);
	else if(c == '\0')
		return(c);
	else
		return(0);
}


int plus_or_minus(int c)
{
	if(c == '+')
		return(c);
	else if(c == '-')
		return(c);
	else
		return(0);
}

int equal_str(char * s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if(s1[i]!=s2[i])
		{
			return(0);
		}
		i++;
	}
	return(i);
}
