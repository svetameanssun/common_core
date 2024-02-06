# include <stdio.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	result;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		result = b;
	else
		result = a;
	while (1)
	{
		if (result % a == 0 && result % b == 0)
			return (result);
		result++;
	}
}

int main()
{
    printf("%i", lcm(4,6));
    return (0);
}
