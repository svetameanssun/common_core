# include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void ft_swap_str( char *c, char*d)
{
    char temp;

    temp = *c;
    *c = *d;
    *d = temp;
}

int main()
{
    int a = 0;
    int b = 22;

    char c = 'c';
    char d = 'd';

    ft_swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    ft_swap_str(&c, &d);
    printf("%c\n", c);
    printf("%c\n", d);

    
}