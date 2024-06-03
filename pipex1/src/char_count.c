#include "../include/pipex.h"
#include "../libft/libft.h"

int char_count(int c, char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			count++;
		i++;
	}
	return(count);

}

