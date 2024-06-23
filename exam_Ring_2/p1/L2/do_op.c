# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>



int calculate(char *arg1, char operator, char *arg2)
{
    int res;
    if (operator == '+')
    {
        res = atoi(arg1) + atoi(arg2);
    }
    else if (operator == '-')
    {
        res = atoi(arg1) - atoi(arg2);
    }
    else if (operator == '/')
    {
        res = atoi(arg1) / atoi(arg2);
    }
    else if (operator == '%')
    {
        res = atoi(arg1) % atoi(arg2);
    }
    else if (operator == '*')
    {
        res = atoi(arg1) * atoi(arg2);
    }
    else
    {
        return (0);
    } 
    printf("%d\n", res);
    return (1);
}


int main(int argc, char ** argv)
{
    if (argc == 4)
    {
        calculate(argv[1], argv[2][0], argv[3]);
    }
    else
        write(1, "\n", 1);
}