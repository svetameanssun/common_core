# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

// dest, src

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;

    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

int main()
{
    char s2[6] = "sveta";
    char *s1= malloc(sizeof(char) * 6);
    ft_strcpy(s1, s2);
    printf("%s",s1);
}