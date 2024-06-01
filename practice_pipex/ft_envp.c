#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}




char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		if (!new)
			return (0);
		new[0] = '\0';
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}

static int	ft_count_elems(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
		else
			i++;
	}
	return (count);
}

static void	ft_free(char **str, int str_ind)
{
	while (str_ind-- > 0)
		free(str[str_ind]);
	free(str);
}

static size_t	ft_substr_len(char const *s, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**double_dimen;
	int		count;
	int		elem_num;

	count = 0;
	elem_num = ft_count_elems(s, c);
	double_dimen = (char **)malloc(sizeof(char *) * (ft_count_elems(s, c) + 1));
	if (double_dimen == NULL)
		return (NULL);
	while (count < elem_num)
	{
		while (*s == c)
			s++;
		double_dimen[count] = ft_substr(s, 0, ft_substr_len(s, c));
		if (!(double_dimen[count]))
		{
			ft_free(double_dimen, count);
			return (0);
		}
		while (*s != c && *s)
			s++;
		count++;
	}
	double_dimen[count] = NULL;
	return (double_dimen);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t len_s1 = ft_strlen(s1);
	size_t len_s2 = ft_strlen(s2);

	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	new = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (len_s1 + len_s2))
	{
		new[i] = s2[i - len_s1];
		i++;
	}
	new[i] = '\0';
	return (new);
}


int main(int argc, char ** argv, char **envp)
{
    char *full_path;
    char **path_splited;
    while(*envp)
    {
        if (strncmp(*envp, "PATH=", 5) == 0)
        {
            full_path = (*envp +5);
            break;
        }
        envp++;
    }
    int i = 0;
    printf("%s\n", full_path);
    path_splited = ft_split(full_path, ':');
    int j = 0;
    while(path_splited[j])
    {
        printf("%s\n", path_splited[j]);
        j++;
    }

    char *cmd_path;
    char **cmd;
    cmd = ft_split("ls -al", ' ');
    while (path_splited[i])
	{
		cmd_path = ft_strjoin(ft_strjoin(path_splited[i], "/"), cmd[0]);
        printf("THIS!!!! ---> %s\n",cmd_path);
        int err_n;
        if ((err_n =access(cmd_path, X_OK)) == 0)
        {    
            break;
        }
        printf("%d\n", err_n);
		free(cmd_path);
		cmd_path = NULL;
        i++;
	}

    return(0);

}