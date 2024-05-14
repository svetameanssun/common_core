#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char ** argv)
{
	if (mkfifo("my_fifo1", 0777) == -1)
	{
		if (errno != EEXIST)
		{	printf("could not createI a fifo file\n");
			return(1);
		}
	}
	printf("Opening...\n");
	int fd = open("my_fifo1", O_WRONLY);
	//int fd = open("my_fifo1", O_RDWR);
	printf("Opened...\n");
	int x = 97;
	if (write(fd, &x, sizeof(x)) == -1)
	{
		return(2);
	}
	printf("Written\n");

	close(fd);
	printf("Closed\n");

	return(0);
}
