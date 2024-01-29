# include <unistd.h>
# include <string.h>
/* s1 = destino
s2 = source */

/*char    *ft_strcpy(char *s1, char *s2)
{
    char *aux = s1;
    if (s1 == NULL)
        return(NULL);
    if (s2 == NULL)
        return (s1);

    while(*s2!= '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
    return (aux);
}*/

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while(s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    return(s1);
}


# include <stdio.h>
# include <unistd.h>

void ft_putstr(char * str)
{
    while(*str!= '\0')
    {
        write(1, str, 1);
        str++;
    }
}

int main()
{
    char dest[10] = "sss";
    char source[10] = "ttttt";
    char dst[10] = "sss";
    char srce[10] = "ttttt";
    ft_putstr(strcpy(dest,source));
    write(1, "\n", 1);
    ft_putstr(ft_strcpy(dst,srce));
    return 0;
}