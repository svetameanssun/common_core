# include <unistd.h>

/*int ft_strchr(char *str,int c)
{
    while(str)
    {
        if(*str == c)
        {
            return(c);
        }
        str++;
    }
    return(0);
}



void inter(char *str1, char *str2)
{
    while(str1)
    {
        if()
    }
}




int main(int count, char ** double_arr)
{
    if (count == 3)
    {
        inter(double_arr[1], double_arr[2]);
    }
    write(1, "\n", 1);
}*/
#include <unistd.h>

int	inter(char *str, char c, int len)
{
	int	i = 0;

	while (str[i] && (i < len || len == -1))
    {
		if (str[i++] == c)
        {
			return (1);
        }
    }
	return (0);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (!inter(argv[1], argv[1][i], i) && inter(argv[2], argv[1][i], -1))
				write(1, &argv[1][i], 1);
			i += 1;
		}
	}
	write(1, "\n", 1);
	return (0);
}