unsigned char	reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char res;

    while(i > 0)
    {
        res = res * 2 + (octet % i);
        octet = res / 2;
        i--;
    }
    return(res);

}