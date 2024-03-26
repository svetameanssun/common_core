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
