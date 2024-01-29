# include <stdlib.h>
# include "check_ascii.c"
# include <unistd.h>
# include <stdio.h>

size_t ft_strlen(char *str)
{
    int count;

    count = 0;
    while(str[count] != '\0')
        count++;
    return (count);
}
/*char *ft_strchar(const char *str, int c)
{
    size_t i;
    char *aux;

    i = 0;
    aux = (char *)str;
    while (str[i] != (char)c)
    {
        if (aux[i] == '\0')
            return (0);
        i++;         
    }
    return (aux + i);
}*/

char *ft_strchar(const char *str, int c)
{
    
}



int main(void)
{

    

}

