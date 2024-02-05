# include <unistd.h>

int ft_is_char(int c)
{
    return (c >= 33 && c <= 126);
}

int ft_is_space(int c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

void ft_expand_str(char *str)
{
    int flg;
    while(ft_is_space(*str))
    {
        str++;
    }
    while(*str)
    {
        if(ft_is_space(*str))
        {
            flg = 1;
        }
        if(!ft_is_space(*str))
        {
            if(flg)
            {
                write(1, "   ", 3);
            }
            flg = 0;
            write(1, str,1);
        }
        str++;
    }
}


int main(int argc, char ** argv)
{
    if(argc == 2)
    {
        ft_expand_str(argv[1]);
    }
    write(1, "\n", 1);
}