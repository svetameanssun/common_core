# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


int ft_strlen(char *str)
{
    int len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    return(len);
}

int is_space(int c)
{
    return(c == ' ' || c == '\n' || c == '\t');
}

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}


int ft_wdcount(char *str)
{
    int i = 0;
    int wc = 0;
    while(str[i])
    {
        while(is_space(str[i]))
        {
            i++;
        }
        if(str[i])
        {
            wc++;
        }
        while(is_printable(str[i]))
        {
            i++;
        }
    }
    return (wc);
}

void ft_putword(char *str, int start, int end)
{

    while(start < end)
    {
        write(1, &str[start], 1);
        start++;
    }

}

void rostring(char *str)
{
    int wc = ft_wdcount(str);
    int start = 0;
    int end = 0;
    int i = 0;

    while(str[i] && is_space(str[i]))
    {
        i++;
    }
    start = i;
    while(str[i] && is_printable(str[i]))
    {
        i++;
    }
    end = i;
    while(wc && str[i])
    {
        while(str[i] && is_space(str[i]))
        {
            i++;
        }
        
        while(str[i] && is_printable(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        if(wc != 1)
        {
            write(1, " ", 1);
        }
        wc--;
    }
    while(start < end)
    {
        write(1, &str[start],1);
        start++;
    }


}

int main(int argc, char **argv)
{
    if(argc > 1)
    {
        rostring(argv[1]);
    }
    write(1, "\n", 1);
}