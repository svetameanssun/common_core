/*Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$*/

#include <unistd.h>

int inter(char *str, int c, int index)
{
    int j = 0;
    while(str[j] &&( j < index || index == -1))
    {
        if(str[j] == c)
        {
            return(1);
        }
        j++;
    }
    return(0);
}

int main(int argc, char **argv)
{
    int i = 0;
    if(argc ==3)
    {   while(argv[1][i])
        {
            if(!inter(argv[1], argv[1][i], i) && inter(argv[2], argv[1][i], -1))
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}


/*int inter(char * str, int c, int index)
{
    int i = 0;
    while(str[i] && (index < i || index == -1))
    {
        if(str[i] == c )
        {
            return(1);
        }
        i++;
    }
    return(0);
}
int main(int argc, char ** argv)
{
    int i = 0;
    while(argv[1][i])
    {
        if(!inter(argv[1], argv[1][i], i) && inter(argv[2], argv[1][i], -1))
            write(1, &argv[1][i], 1);
        i++;
    }
    return(0);
}*/