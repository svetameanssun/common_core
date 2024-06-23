# include <stdio.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i = 0;
    int j = 0;
    while(accept[i])
    {
        j = 0;
        while(s[j])
        {
            if (s[j] != accept[j])
                return(j);
            j++;
        }
        i++;
    }
    return(j);
}

int main()
{
    printf("%ld\n", ft_strspn("qwqwqwqwq", "q"));
    printf("%ld\n", strspn("qwqwqwqwq", "q"));
}