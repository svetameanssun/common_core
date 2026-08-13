1. #include "ft_printf.h"

int main(void)
{
ft_printf("%%%diuxX%s, %c", 5,"hola", 'c');
return (0);
}

2. gcc main.c -L. -lftprintf -o my_program

OR

3)gcc main.c libftprintf.a -o my_program

./my_program
