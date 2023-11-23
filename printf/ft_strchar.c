int	int_putchar(char c)
{
	write(1, &c, 1);
    return(1);
}

int	int_putstr(char *str)
{
    int count;

    count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
        count++;
	}
    return(count);
}