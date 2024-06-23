# include <unistd.h>

void snake_to_camel(char *str)
{
    char aux;
    while(*str != '\0')
    {
        if(*str == '_')
        {
            str++;
            aux = *str - 32; 
            write(1, &aux, 1);
        }
        else
            write(1, str, 1);
        str++;
    }
}



int main(int argc, char ** argv)
{
    if ( argc == 2)
    {
        snake_to_camel(argv[1]);
    }
    write(1,"\n",1);
}