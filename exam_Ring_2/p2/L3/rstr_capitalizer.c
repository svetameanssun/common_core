# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int is_lower(int c)
{
    return(c >= 'a'&& c <= 'z');
}
int is_upper(int c)
{
    return(c >= 'A'&& c <= 'Z');
}
int alpha(int c)
{
    return(is_upper(c) || is_lower(c));
}
int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}

void rstr_capitalizer(char * str)
{
    int i = 0;
    int j = 1;
    /*while(str[i] == ' ')
    {        
        write(1, &str[i],1);
        i++;
    }*/
    while(str[i])
    {

        if (is_upper(str[i]) && alpha(str[j]))
            str[i] = str[i] + 32;
        if (is_lower(str[i]) && (str[j] == ' ' || str[j] == '\0' ))
            str[i] = str[i] - 32;
        write(1, &str[i], 1);
        i++;
        j++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc == 1)
        write(1, "\n", 1);
    else
    {   
        while(i < argc)
        {
            rstr_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
}