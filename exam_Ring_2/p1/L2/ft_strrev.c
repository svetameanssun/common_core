# include <stdio.h>

char    *ft_strrev(char *str)
{
    int i = -1;
    int length = 0;
    char aux;

    while (str[length])
    {
        length++;
    }

    while(++i < length / 2)
    {
        aux = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = aux;
    }
    return(str);
}

int main()
{
    char str[6] = "sveta"; 
    printf("%s",ft_strrev(str));
}