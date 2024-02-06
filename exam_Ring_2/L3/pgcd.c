# include <stdio.h>
# include <stdlib.h>




void pgcd(char *n1, char *n2)
{
    int nbr1 = atoi(n1);
    int nbr2 = atoi(n2);

    if (nbr1 > 0 && nbr2 > 0)
    {
        while(nbr1 != nbr2)
        {
            if( nbr1 > nbr2)
                nbr1  = nbr1 - nbr2;
            else
                nbr2 = nbr2 - nbr1;
        }
        printf("%d", nbr1);
    }
    
}



int main(int argc, char ** argv)
{
    if (argc == 3)
    {
        pgcd(argv[1], argv[2]);
    }
    printf("\n");
}