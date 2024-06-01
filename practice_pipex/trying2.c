#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	char buffer[1024];
	 int file_fd = open("my_file.txt", O_RDONLY);
	int read_fd = read(file_fd, buffer, 100);
	
	char path[] = "/usr/bin/ls";
    	char * argc[] = {"ls", NULL};
	char * envv[] = {NULL};	

	close(file_fd);
	execve(path, argc, envv);
	return(0);
}
