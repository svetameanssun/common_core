int check_part(const char *str)
{
    if(str[0] == '%' && cspdiux(str[1]))
        return(cspdiux(str[1]));
    return(0);
}

char cspdiux(char c);
{
    return(c == 'c' || c == 's'|| c == 'd'|| c == 'i'
    || c == 'u'|| c == 'x'|| c == 'X'|| c == '%'|| c == 'p');
}