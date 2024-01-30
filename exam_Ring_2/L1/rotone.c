# include <unistd.h>


void rotone(char *str)
{
    char printed_c;
    int i = 0;
    while(str[i]!= '\0')
    {
        if(( str[i] >= 'a' && str[i] <= 'y') || ( str[i] >= 'A' && str[i] <= 'Y'))
            printed_c = str[i] + 1;
        else if( str[i] >= 'z' || str[i] <= 'Z')
            printed_c = str[i] - 25;
        else
            printed_c = str[i];
        write(1, &printed_c, 1);
        i++;
    }
    write(1, "\n", 1);
}


int main()
{
    rotone("Z");
}