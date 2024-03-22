#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
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
