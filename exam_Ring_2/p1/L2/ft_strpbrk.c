# include <unistd.h>
# include <stdio.h>

char * ft_strchr(const char *s, int c)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
        {
            return (char*)&s[i];
        }
        i++;
    }
    return (NULL);
}




char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0')
    {
        if(ft_strchr(s1, s2[i]))
        {
            //printf("%p",ft_strchr(s1, s2[i]));
            return(ft_strchr(s1, s2[i]));
        }
        i++;
    }
    return(NULL);

}

int main(int argc,char ** argv)
{
	if ( argc == 3)
	{
		printf("%s\n",ft_strpbrk(argv[1], argv[2]));
	}
}

