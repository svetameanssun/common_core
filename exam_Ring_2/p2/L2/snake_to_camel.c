#include <unistd.h>
#include <stdio.h>

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}
int is_alpha(int c)
{
    return((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int is_lower(int c)
{
    return(c >= 'a' && c <= 'z');
}

int word_count(char *str)
{
    int count = 0;
    int i  = 0;
    int j = 1;
    while(str[i])
    {
        if(is_printable(str[i]) && (str[j] == ' ' || str[j] == '\0'))
        {
            count++;
        }
        i++;
        j++;
    }
    return(count);
}

void snake_to_camel(char * str)
{
    int wrd_cnt = word_count(str);
    int i = 0;
    int j = 1;
    while(str[i])
    {
        if(is_alpha(str[i]) && str[j] == '_' && is_lower(str[j + 1]))
        {
            str[j+1] = str[j + 1] - 32;
            write(1, &str[i], 1);
            i+=2;
            j+=2;
        }
        write(1, &str[i], 1);
        i++;
        j++;
        
    }

}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        snake_to_camel(argv[1]);
    }
    write(1, "\n", 1);
}
