#include <unistd.h>
#include <stdio.h>


int main()
{
	char cmd_path[] = "/usr/bin/ls";
	char* argVec [] = {"ls", NULL};
	char * envVec[] = {NULL};
	printf("Start executing excve %s\n", cmd_path);
	printf("------------------------------\n");				
	if(execve(cmd_path, argVec, envVec) == -1)
	{
		perror("Could not execute execve");
	}
	printf("something went wrong!");
	return(0);

}
