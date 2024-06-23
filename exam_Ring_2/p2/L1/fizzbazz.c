# include <stdio.h>
# include <unistd.h>
/*Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.*/
//100
void putnbr(int n)
{
    char numbers[11] = "0123456789";
    if(n > 9)
        putnbr(n/10);
    write(1, &numbers[n%10] , 1);

}


int main()
{
    int i = 1;

    while(i < 101)
    {
        if (i%3 == 0 && i%5 == 0)
            write(1, "fizzbuzz", 9);
        else if (i%3 == 0)
            write(1, "fizz", 5);
        else if (i%5 == 0)
            write(1, "buzz", 5);
        else
            putnbr(i);
        write(1, "\n", 1);
        i++;
    }
    
}