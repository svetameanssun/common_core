# include <unistd.h>
# include <stdio.h>

int ft_atoi(char *str)
{
    int i = 0;
    int number = 0;
    while(str[i])
    {
        if(str[i] > '9' || str[i] < '0')
            return(0);
        i++;
    }
    i = 0;
    //char decstr[10] = "0123456789";

    while(str[i])
    {
        number = number * 10 + str[i] - 48;
        i++;
    }
    return (number);
}


int print_hex(char *dec_str)
{
    int dec_num = ft_atoi(dec_str);
    char hex_str[16] = "0123456789abcdef";
    

    

}



int main(int c, char **v)
{
    if (c == 2)
    {
        print_hex(v[1]);
    }
    write(1, "\n",1);
}