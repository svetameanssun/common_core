# include <unistd.h>
# include <stdio.h>

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bits;

    while(i--)
    {
        bits = (octet >> i & 1) + '0';
        write(1, &bits, 1);
    }
}

/*void print_4_bits(unsigned char octet)
{
    int i = 4;
    unsigned char bits;

    while(i--)
    {
        bits = (octet >> i & 1) + '0';
        write(1, &bits, 1);
    }
}*/

unsigned char swap_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
}



unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}
int main()
{
    print_bits(13);
    write(1, "\n", 1);

    /*print_bits(swap_bits(13));
    write(1, "\n", 1);*/
    unsigned char bits = reverse_bits(13);

    print_bits(reverse_bits(13));
}