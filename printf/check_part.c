int check_part(const char *str)
{
    if(str[0] == '%' && cspdiux(str[1]))
        return(cspdiux(str[1]));
    return(0);
}

int cspdiux(char c);
{
    if(c == 'c')
        return(1);
    if(c == 's')
        return(2);
    if(c == 'p')
        return(3);
    if(c == 'd')
        return(4);
    if(c == 'i')
        return(5);
    if(c == 'u')
        return(6);
    if(c == 'x')
        return(7);
    if(c == 'X')
        return(8);
    if(c == '%')
        return(9);
    return(0);
}