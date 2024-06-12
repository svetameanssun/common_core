#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	size_s1;
	size_t	size_s1_s2;

	size_s1 = ft_strlen_gnl(s1);
	size_s1_s2 = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	new = (char *)malloc(sizeof(char) * (size_s1_s2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (size_s1_s2))
	{
		new[i] = s2[i - size_s1];
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

int main(int argc, char **argv)
{
    printf("%ld", ft_strlen(argv[1]));
    printf("%ld", ft_strlen_gnl(argv[1]));
}

