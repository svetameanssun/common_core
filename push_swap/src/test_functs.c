#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"


int	united_str_size(int arg_num, char **arguments)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	if (arg_num == 1)
		return(0);
	while (i < arg_num)
	{
		j = 0;
		while (arguments[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	count = count + arg_num - 2;
	return (count);
}

char	*words_to_str(int argc, char **argv)
{
	int		i;
	int		j;
	int		res_size;
	char	*res;
	int		k;

	i = 1;
	j = 0;
	if (argc == 1)
		return(0);
	res_size = united_str_size(argc, argv);
	res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (!res)
		return (0);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
			res[j++] = argv[i][k++];
		if (i < argc - 1)
			res[j] = ' ';
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

int main(int arg_num, char **arguments)
{
    printf("%d", united_str_size(arg_num, arguments));
	printf("%s", words_to_str(arg_num, arguments));
}