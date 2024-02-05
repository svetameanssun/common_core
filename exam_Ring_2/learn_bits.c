# include <unistd.h>
# include <stdio.h>

int main()
{
   int i = 4;
   unsigned char octet = 11;
   unsigned char bit;

   while(i--)
    {
     
     bit = (octet >> i  & 1)+ '0';
     write(1, &bit, 1);
    }
}