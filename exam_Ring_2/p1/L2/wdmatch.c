# include <unistd.h>

void ft_strchr(char *str, int c)
{
    while(*str)
    {
        if(*str == c)
        {
            write(1, &c,1);
        }
        str++;
        
    }
}

void wdmatch(char *s1, char * s2)
{
    int i = 0;
    while(s1[i] != '\0')
    {
        ft_strchr(s2,s1[i]);
        i++;
        
    }
}


int main (int argc, char ** argv)
{
    if (argc ==3)
    {
        wdmatch(argv[1], argv[2]);
    }
    write(1,"\n",1);
}