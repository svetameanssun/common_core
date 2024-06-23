#include <stdio.h>

void change_ptr(char **str)
{
    char *str2 = "adios";
    *str = str2;
    /*printf("%s\n", *str);
    printf("%c\n", **str);*/
}

int main(void)
{
    char *str = "hola";

    change_ptr(&str);
    printf("%s\n", str);
    return (0);
}