#include <unistd.h>


void last_word(char *str)
{
	int i = 0;
	int save_point = 0;
	while(str[i] != '\0')
	{
		if((str[i] == ' ') && (str[i+1] >= 33 && str[i +1] <=126))
		{
			save_point = i+1;
		}
		i++;
	}
	while(str[save_point])
	{
		if(str[save_point] >= 33 && str[save_point] <= 126)
		{
			write(1, &str[save_point],1);
		}
		save_point++;
	}
}

int main(int argc,char ** argv)
{
	if ( argc == 2)
	{
		last_word(argv[1]);
	}
	write(1,"\n",1);
}
