/*Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>*/

#include <unistd.h>
#include <stdio.h>

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
    return(is_upper(c) || is_lower(c));
}

void repeat_alpha(char *str)
{
    int i = 0;
    int flag = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        if(is_alpha(str[i]))
        {
            if(is_lower(str[i]))
                flag = str[i] - 97;
            if(is_upper(str[i]))
                flag = str[i] - 65;
            
        }
        while(flag)
        {
            write(1, &str[i], 1);
            flag--;
        }
        i++;
    }

}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
    return(0);
}