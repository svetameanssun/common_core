#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(int argc, char ** argv, char ** envv)
{
	int pipe_fd[2];
	int pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid == -1)
		perror("Fork hasn't been created");
	else if(pid == 0)
	{
		int fd_file = open("new_file", O_RDONLY | O_CREAT, 0777);
		dup2(fd_file,STDIN_FILENO);
		execve("/usr/bin/ls", argv, envv);
	}		
	wait(NULL);	
	return(0);
}
