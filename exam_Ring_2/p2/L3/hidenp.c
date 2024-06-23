/*Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline.

Examples :

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>*/

int find_char(int c, char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return(i);
        i++;
    }
    return(0);
}


# include <stdio.h>
# include <unistd.h>

int hidenp(char *s1, char *s2)
{
    int i = 0;
    int j = 1;
    int found;

    if (s1 == NULL)
        return(1);
    while(s1[i])
    {
        if(found = find_char(s1[i], s2) > 0)
        {
            j = j + found;
            s2  = s2 + j;
        }
        else
            return(0); 
        i++;
    }
    return(1);
}

int main(int argc, char **argv)
{
    //printf("%d", find_char('v', "sveta"));


    int res;
    if (argc == 3)
    {
        res = hidenp(argv[1], argv[2]);
        res += '0';
        write(1, &res, 1);
    }
    write(1, "\n", 1);
    return(0);
}