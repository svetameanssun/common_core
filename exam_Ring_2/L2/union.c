# include <unistd.h>
int ft_strchr(char *str, int c)
{
    while(*str)
    {
        if(*str == c)
        {
            return (c);
        }
        str++;
        
    }
    return 0;
}



void ft_union(char *s1, char *s2)
{
    while(*s1)
    {
        if(ft_strchr(s2, *s1))
        {
            write(1, s1, 1);
        }
        s1++;
    }
}


int main(int argc, char ** argv)
{
    if (argc == 3)
    {
        ft_union(argv[1], argv[2]);
    }
    write(1,"\n",1);
}