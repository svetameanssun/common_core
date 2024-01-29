# include <unistd.h>
# include <stdio.h>

/*void ft_write_pos(int number)
{
    char str[10] = "0123456789";
    if (number > 9)
        ft_write_pos(number/10);
    write(1, &str[number%10],1);
}
int main()
{
    int i =1;
    while( i <=10)
    {
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz" , 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            ft_write_pos(i);
        i++;
        write(1,"\n",1);
    }
}*/