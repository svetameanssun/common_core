#include <unistd.h>

void put_nbr(int nbr)
{
    char digit;

    if (nbr >= 10)
    {
        put_nbr(nbr/10);
    }
    digit = nbr%10 + '0';
    write(1, &digit,1);


}


int main (int argc, char ** argv)
{
    (void)argv;

    put_nbr(argc-1);
    write(1, "\n",1 );
    return(0);
}