# include <unistd.h>
# include <stdio.h>

int var = 222;

int main(void)
{
    pid_t pidC;

    pidC = -11111;
    
    printf("-------------------------\n");
    printf("** Father process starting, PID = %d, pidC = %d  **\n", getpid(), pidC);
    printf("+++++++++++++++++++++++++\n");
    printf("FORKING:\n");
    pidC = fork();
    printf("=========================\n");
    printf("**Process executing, PID = %d, pidC = %d  **\n", getpid(), pidC);
    if (pidC == 0)
    {
	    /*printf("** Child process, PID = %d, myChild = %d **\n", getpid(), pidC);*/
	    var = 2;    }
    else if (pidC > 0)
    {
    	/*printf("** Father process, PID = %d, myChild = %d **\n", getpid(), pidC);*/
    	    var = 2222222;
    }
    else if(pidC < 0)
    {
	printf("ERROR\n");
    }

    while(1)
    {
	sleep(3);
	printf("^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("proc. PID = %d, myChild = %d, var = %d  executing\n", getpid(),pidC, var);
    }
    return 0;
}
