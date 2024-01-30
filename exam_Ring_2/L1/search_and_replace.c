# include <unistd.h>

void substitude(char *str, char *old, char *new)
{
    int i = 0;
    if(old[1] == '\0' && new[1] == '\0')
    {
        while(str[i] != '\0')
        {
            if (str[i] == *old)
            {
                write(1, new, 1);
            }
            else
                write(1, &str[i], 1);
            i++;
        }
    }
}


int main (int argc, char ** argv)
{
    if (argc == 4)
    {
        substitude(argv[1], argv[2], argv[3]);
    }
    write(1, "\n", 1);
}