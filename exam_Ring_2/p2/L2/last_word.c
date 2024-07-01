/*Write a program that takes a string and displays its last word followed by a "\n".

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/
#include <stdio.h>
#include <unistd.h>

int is_printable(int c)
{
    return(c >=33 && c <= 126);
}
int is_space(int c)
{
    return(c == '\t' || c == '\n' 
    || c == ' ' || c == '\r'
    || c == '\v' || c == '\f');
}

int word_count(char *str)
{
    int i = 0;
    int j = 1;
    int count = 0;
    while(str[i])
    {
        if(is_printable(str[i]) && (is_space(str[j]) || str[j] == '\0'))
        {
            count++;
        }
        i++;
        j++;
    }
    return(count);
}
void last_word(char * str)
{
    int i = 0;
    int wrd_cnt = word_count(str);
    while(wrd_cnt)
    {
        while(is_space(str[i]))
        {
            i++;
        }
        if(wrd_cnt == 1)
        {
            while(is_printable(str[i]) && str[i] !='\0')
            {
                write(1, &str[i], 1);
                i++;
            }
        }
        else
        {
            while(is_printable(str[i]))
                i++;
        }
        wrd_cnt--;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        last_word(argv[1]);
    }
    write(1, "\n", 1);
    
}