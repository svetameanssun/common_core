# include <unistd.h>
# include <stdio.h>

void print_rot_13(char *str)
{
    char print_c;
    int i = 0;
    while(str[i] !='\0')
    {
        
        if((str[i] >= 'a' && str[i] <= 'z'))
        {
            print_c = (str[i] - 'a' + 13) % 26 + 'a';
            
        }
        else if(str[i] >= 'A' && str[i] <= 'Z') 
        {
            print_c = (str[i] - 'A' + 13) % 26 + 'A';
        }
        
        write(1, &print_c, 1);
        i++;
    }
}

int main(int argc, char ** argv)
{
    if (argc == 2)
    {
        print_rot_13(argv[1]);
    }
    write(1, "\n", 1);
}