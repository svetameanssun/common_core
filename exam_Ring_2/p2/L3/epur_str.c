# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int is_printable(int c)
{
    return((c >= 33 && c <= 126));
}

int word_count(char *str)
{
    int i = 0;
    int j = 0;
    int count = 0;

    while(str[i] == ' ')
    {
        i++;
    }
    j = i + 1;

    while(str[i])
    {
        if (is_printable(str[i])  && (str[j] == ' ' || str[j] == '\0'))
        {
            count++;
        }

        i++;
        j++;
    }
    return(count);
}

void epur_str(char *str)
{
    int wrds = word_count(str);
    int i = 0;
    while(str[i] == ' ')
    {
        i++;
    }
    while(wrds)
    {
        if(wrds > 1)
        {
            while(is_printable(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
            while(str[i] == ' ')
            {
                i++;
            }
        }
        else if (wrds == 1)
        {
            while(str[i]!= '\0' && str[i] != ' ')
            {
                write(1, &str[i], 1);
                i++;
            }
        }

        wrds--;
    
    }

}

int main(int argc, char ** argv)
{
    if (argc == 2)
        epur_str(argv[1]);
    write(1, "\n", 1);
}