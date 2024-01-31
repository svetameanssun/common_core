# include <unistd.h>

void alpha_mirror(char * str)
{
    int i = 0;
    char print_char;

    while(str[i] != '\0')
    {
        if(str[i] >='a'&& str[i] <= 'z')
        {
            print_char = 'z' - str[i] + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            print_char = 'Z' - str[i] + 'A';
        }
        write(1, &print_char, 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
       alpha_mirror(argv[1]); 
    }
    write(1,"\n",1);
}