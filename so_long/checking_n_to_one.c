#include <stdio.h>

void n_to_one(char **copymap)
{
	char ** save;
	int i;
	int j;

	save = copymap;
	i = 0;
	j = 0;
	
	while(copymap[i]!= NULL)
	{
		printf("%d\n", i);
		j = 0;
		while(copymap[i][j] != '\0')
		{
			printf("%d\n", j);
			if(copymap[i][j] == 'N')
				copymap[i][j] = '1';
			j++;
		}
		i++;
	}
}

int main()
{
	char str1[9] = "NamableN";
	char *str[2];
	str[0] = str1;
	str[1] = NULL;
	n_to_one(str);
	printf("%s\n", *str);

}