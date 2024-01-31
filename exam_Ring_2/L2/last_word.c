#include <unistd.h>

void write_from_point(char *str, int point)
{
	int i = point;
	while(str[i] != '\0')
	{
		if(str[i] != ' '&& str[i] != '\t')
		{	
			write(1,&str[i],1);
		} i++;	
	}
}

void last_word(char *str)
{
	int i = 0;
	int save_point;
	while(str[i] != '\0')
	{
		if((str[i] == ' ') && (str[i+1] != ' ' && str[i+1] != '\0'))
		{
			save_point = i;
		}
		i++;
	}
	
	write_from_point(str, save_point);

}

int main(int argc,char ** argv)
{
	if ( argc == 2)
	{
		last_word(argv[1]);
	}
	write(1,"\n",1);
}
