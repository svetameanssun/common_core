# include <stdio.h>
# include <unistd.h>
# include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    while(reject[i])
    {
        j = 0;
        while(s[j])
        {
            if(s[j] == reject[i])
                return(j);
            j++;
        }
        i++;
    }
    return(j);
}

int main()
{
    printf("%ld\n",ft_strcspn("abc", "qwc"));
    printf("%ld", strcspn("abc", "qwc"));
    return(0);
}