# include <stdio.h>

void	ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 22;
    int b = 0;

    ft_swap(&a, &b);
    printf("%d", a);
    printf("%d", b);

    
}