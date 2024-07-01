/*Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>*/
#include <stdio.h>
#include <unistd.h>

int is_lower(int c)
{
    return(c >= 'a' && c <= 'z');
}

int is_upper(int c)
{
    return(c >= 'A' && c <= 'Z');
}
int is_alpha(int c)
{
    return(is_lower(c) || is_upper(c));
}

int is_printable(int c)
{
    return(c >= 33 && c <= 126);
}
int is_space(int c)
{
    return(c == '\t' || c == ' ' || c == '\n'
        || c == '\r' || c == '\v' || c == '\f');
}

int word_count(char *str)
{
    int i = 0;
    int j = 1;
    int count = 0;
    while(str[i])
    {
        if(is_printable(str[i]) && (is_space(str[j]) || str[j] == '\0'))
            count++;
        i++;
        j++;
    }
    return(count);
}
void str_capitalizer(char *str)
{
    int i = 0;
    int wrd_cnt = word_count(str);
    if(is_lower(str[i]))
    {
        str[i] -= 32;
    }
    write(1, &str[i],1);
    i++;

    while(str[i])
    {
        if (is_space(str[i - 1]) && is_lower(str[i]))
            str[i] -= 32;
        if(is_printable(str[i - 1]) && is_upper(str[i]))
            str[i] +=32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc,char ** argv)
{
    int i = 1;
    if(argc > 1)
    {
        while(i < argc)
        {
        str_capitalizer(argv[i]);
        write(1, "\n", 1);
        i++;
        }
    }
    else
        write(1, "\n", 1);
}