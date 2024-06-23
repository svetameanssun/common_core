# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

char    *ft_strdup(char *src)
{
    int len = 0;
    char * dest;
    int i = 0;

    while(src[len])
    {
        len++;
    }

    dest = (char*)malloc(sizeof(char)*(len+1));
    while(src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return(dest);
}

int main()
{
    printf("%s\n",ft_strdup(" sveta"));
    printf("%s\n",strdup(" sveta"));
}