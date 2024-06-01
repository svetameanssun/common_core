#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char ** argv)
{
	int frk_rtn;
	frk_rtn = fork();
	
	if(frk_rtn ==0)
		sleep(1);

	printf("Current process = %d, Parent process = %d, Child process = %d\n" ,getpid(), getppid(), frk_rtn);	
	
	/*in wait_rtn we get a process id we actually waited for!!!*/
	int wait_rtn = wait(NULL);
	if(wait_rtn == -1)
	{
		printf("I have no children to wait for!\n");
	}else
	{
		printf("I am a parent, my child %d finished execution\n", wait_rtn);
	}

	return(0);
}
