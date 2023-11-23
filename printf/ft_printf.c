#include <stdarg.h>

int print_arg(va_list ptr_args, char c)
{
    if (c == 'c')
        return(int_putchar(va_arg(ptr_args,char)))
    if (c == 's')
        return(int_putstr(va_arg(ptr_args,char *)));
    if (c == 'p')
		return (int_putptr(va_arg(ptr_args, unsigned long int)));
	if (c == 'd' || c == 'i')
		return (int_putnbr(va_arg(ptr_args, int)));
	if (c == 'u')
		return (int_putus(va_arg(ptr_args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (int_puthex(c, va_arg(ptr_args, unsigned int)));
	if (c == '%')
		return (int_putchar(c));
	return (0);

}

int ft_printf(const char *str, ...)
{
    int char_number;
    int i;
    va_list ptr_args;
    
    char_number = 0;
    i = 0;
    va_start(ptr_args, str);
    while(str[i] != '\0')
    {
        if(!check_part(str+i))
        {
            int_putchar(str[i]);
            char_number++;
        }
        else
        {
            char_number += print_arg(ptr_args, check_part(str+i));
            i++;
        }
        i++;
    }
    return (char_number);
}
