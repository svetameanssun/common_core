#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv)
{
	int id;

	id = fork();

	if(id == 0)
	{
		printf("Process id %d\n", id);	
	}
	else
	{
		id = fork();
		printf("Process id %d\n", id);
	}
	return(0);
}
