#include "../include/so_long.h"

int check_chars(char ** matrix)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(matrix[i]!= NULL)
	{
		j = 0;
		while(matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
			if ((matrix[i][j] == '1') || (matrix[i][j] == '0')
			|| (matrix[i][j] == 'P') || (matrix[i][j] == 'N')
			|| (matrix[i][j] == 'E') || (matrix[i][j] == 'C'))
				j++;
			else
				return(1);
		}
		i++;
	}
	return(0);
}

/*int main()
{
	char **split_str;
	char str[] = {"11111111,11111111,11111111,00000000,00000009,CC1CCCCC,EEEEEEEE,NNNNPPPP"};
	split_str = ft_split(str,',');
	printf("%d", check_chars(split_str));
	return(0);
}*/