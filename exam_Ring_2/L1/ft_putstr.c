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



int main ()
{
    char str[6] = "sveta";
    ft_putstr(str);
}