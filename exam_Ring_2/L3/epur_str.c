#include <unistd.h>


int ft_is_char(int c)
{
    return (c >= 33 && c <= 126);
}

int ft_is_space(int c)
{
    return (c == 32 || (c >= 9 && c <= 13));
}

void epur_str(char *str)
{
    int i;
    int flg;

    i == 0;
    while (ft_is_space(str[i]))
    {
        i++;
    }
    char stringy[10] = "   11  2  ";
    while(str[i])
    {
        if(ft_is_space(str[i]))
            flg = 1;
        if(!ft_is_space(str[i]))
        {
            if(flg)
            {
                write(1, " ", 1);
            }
            flg = 0;
            write(1, &str[i], 1);
        }
        i++;
    }
}


int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        epur_str(argv[1]);
    }
    write(1, "\n",1);
}