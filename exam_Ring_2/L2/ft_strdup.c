# include <stdio.h>
# include <stdlib.h>

char *ft_strdup(char *src)
{
	int src_len = 0;
	int i = 0;

	while (src[src_len] != '\0')
	{
		src_len++;
	}

	char *duplicated = (char*)malloc(sizeof(char) * (src_len + 1));
	while (i < src_len)
	{
		duplicated[i] = src[i];
		i++;
	}
	duplicated[i] = '\0';
	return (duplicated);
	
}
int main()
{
 char sv[5] = "sveta";
 char * s1 = ft_strdup(sv);
 printf("%s\n", s1);
}
