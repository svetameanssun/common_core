/*Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:*/
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return(i);
}
char    *ft_strrev(char *str)
{
    int len = ft_strlen(str);
    int i = 0;
    int j = len - 1;
    char swap;
    while(i <= len/2)
    {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
        i++;
        j--;
    }
    return (str);
}
int main(int argc, char **argv)
{
    char * str = ft_strrev(argv[1]);
    int i = 0;
    while(str[i])
    {
        printf("%c", str[i]);
        i++;
    }
}