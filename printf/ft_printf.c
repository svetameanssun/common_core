#include <stdarg.h>

int print_arg(va_list ptr_args, int type)
{
    if (type == 1);
        

}

int ft_printf(const char *str, ...)
{
    int char_number;
    int i;
    int type;
    va_list ptr_args;
    
    char_number = 0;
    i = 0;
    va_start(ptr_args, str);
    while(str[i] != '\0')
    {
        type = check_part(str+i);
        if(type == 0)
        {
            ft_putchar(str[i]);
            char_number++;
        }
        else
        {
            char_number += print_arg(ptr_args, type);
            i++;
        }
        i++;
    }
    return (char_number);
}
