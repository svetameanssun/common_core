# include <stdio.h>
# include <unistd.h>
# include <string.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i = 0;

    while(s2[i] && s1[i])
    {       
        if (s1[i] != s2[i])
            return(s1[i] - s2[i]);
        i++;
    }
    return(s1[i] - s2[i]);
}

int main(int argc, char** argv)
{
    printf("%d\n", ft_strcmp("qaee", "qwee"));
    printf("%d", strcmp("qaee", "qwee"));
}