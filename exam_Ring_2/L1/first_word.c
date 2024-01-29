#include <unistd.h>
# include <stdio.h>

/*char	*first_word(char *find_here, char *find_this)
{
	int		i;
	int		j;
	char	*aux;
	int		i;
	char	c;

	i = 0;
	j = 0;
	if (find_here == find_this)
		return (find_this);
	if (!find_here ||)
		while (find_here[i] != ' ' && find_this != '\0')
		{
			if (find_here[i + j] == find_this[j])
			{
				aux[j] = find_this[j];
				j++;
			}
			else
			{
				j = 0;
				i++;
			}
		}
	return (aux);
}*/
/*int	main(int argc, char **argv)
{
    int i;
	i = 0;
	if (argc == 2)
	{
        while(argv[1][i] == ' ' ||  argv[1][i] == 9)
        {
            i++;
        }
		while ((argv[1][i] != 9 && argv[1][i] != ' ') && argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}*/

/*int main(int argc, char ** argv)
{
	int i = 0;
	
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == 9)
		{
			i++;
		}
		while ((argv[1][i] != ' ' && argv[1][i] != 9) && argv[1][i] != '\0')
		{
			write(1, &argv[1][i],1);
			i++;
		}
	}
	return(0);
}*/

int main(int argc, char **argv)
{
	if( argc ==2)
	{
		argv++;
		while(**argv == ' '|| **argv == 9)
		{
			*argv = *argv +1;
		}
		while((**argv != ' ' && **argv != 9) && **argv != '\0')
		{
			write(1, *argv, 1);
			*argv = *argv +1;
		} 
	}
}