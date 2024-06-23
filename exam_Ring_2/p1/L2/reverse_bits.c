# include <unistd.h>

void reverse_bits(unsigned char octet)
{
    int i = 0;
    unsigned char bits;
    while(i < 8)
    {
        bits = (octet >> i & 1) + '0';
        write(1,&bits,1);
        i++;
    }
}

int main()
{
    
    reverse_bits(13);
    write(1,"\n",1);
}