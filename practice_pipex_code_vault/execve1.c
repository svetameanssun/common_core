#include <stdio.h>
#include <unistd.h>

int main()
{
	char cmd[] = "/usr/bin/ls";
	char * argVec[] = {"ls", NULL};
	char * envVec[] = {NULL};

	printf("Start of execve call %s\n", cmd);
	printf("------------------------------\n");
	if (execve(cmd, argVec, envVec) == -1)
	{
		perror("Could not execute execve");
	}
	printf("Oops, something went wrong");
	
	return(0);
}
