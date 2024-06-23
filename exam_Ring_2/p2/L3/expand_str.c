# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}

int word_count(char *str)
{
    int count = 0;
    int i = 0;
    int j = 0;

    while(str[i] == ' ')
    {
        i++;
    }
    j = i + 1;
    while(str[i])
    {
        if(is_printable(str[i]) && (str[j] == ' ' || str[j] == '\0'))
            count++;
        i++;
        j++;     
    }
    return(count);
}

void expand_str(char *str)
{
    int wrds = word_count(str);
    int i = 0;

    while(str[i] == ' ')
    {
        i++;
    }

    while(wrds)
    {
        if(wrds == 1)
        {
            while(is_printable(str[i]) && (str[i] != ' ' || str[i] != '\0'))
            {
                write(1, &str[i], 1);
                i++;
            }
        }
        else
        {
            while((str[i] != ' '))
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, "   ", 3);
            while(str[i] == ' ')
            {
                i++;
            }
        }
        wrds--;
    }
}

int main(int argc, char **argv)
{
    if(argc ==2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return(0);
}