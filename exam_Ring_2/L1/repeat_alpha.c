# include <unistd.h>

void putchar_n_times(char c, int n)
{
    while ( n > 0)
    {
        write(1, &c, 1);
        n--;
    }
}


void repeat_alpha(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            putchar_n_times(str[i], str[i] +1 - 'a');
        else if (str[i] >= 'A' && str[i] <= 'Z')
            putchar_n_times(str[i], str[i] +1 - 'A');
        else
            putchar_n_times(str[i],1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        repeat_alpha(argv[1]);
    }
}
