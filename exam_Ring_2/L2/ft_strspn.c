# include <unistd.h>
# include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	int i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == c)
		{
			return((char*)&s[i]);
		}
		++i;
	}
	return (0);
}

size_t ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (ft_strchr(accept, s[i]) == 0)
			break;
		++i;
	}
	return (i);

}

int main()
{
	printf("%ld\n", ft_strspn("sveta", "svutu"));
}
