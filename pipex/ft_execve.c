#include <unistd.h>
#include <stdio.h>


int main()
{
	char cmd[] = "/usr/bin/ls";
	char* argVec [] = {"ls", NULL};
	char * envVec[] = {NULL};
	printf("Start executing excve %s\n", cmd);
	printf("------------------------------\n");				
	if(execve(cmd, argVec, envVec) == -1)
	{
		perror("Could not execute execve");
	}
	printf("something went wrong!");
	return(0);

}
