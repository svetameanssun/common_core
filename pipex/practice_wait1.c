# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>

# define NUM_CHILD 5
/* Fork, wait and multiple child processes */
/* macros - WEXITSTATUS(int *wstatus) */
int do_something(void)
{
	int random_num;

	srand(getpid());/*the seed for random number calculation.
	If do do not add the seed, each runtime the same sequence of numbers
	maybe generated*/

	random_num = (rand() % 256);/*just making sure the number is not bigger, than 256*/
	printf("Child, PID = %d, random number = %d \n", getpid(), random_num);
	return(random_num);
}

int main(void)
{
	pid_t pidC;
	int status;

	for (int i = 0; i < NUM_CHILD; i++)
	{
		pidC = fork();

		if (pidC > 0)
		{	/*I want the father to keep generating children*/
			continue;
		}
		else if (pidC == 0)
		{
			/*I do NOT want children to create children*/
			exit(do_something());/*Este es el valor de FINALIZACION(?) de hijo*/
			/*los valores de finalizacion pueden it de 0 a 256*/
			/*el hijo executa esta function y termina*/
		}
		else if (pidC < 0)
		{
			printf("ERROR");
		}
	}
	/*el padre puede esperar que sus hijos terminen
	 * y que valor han retornado estos hijos*/
	for (int i = 0; i < NUM_CHILD; i++)
	{
		/*Como argumento d eentradad necesita un puntero a una variable int*/
		/*Nos devuelve el identificador del roceso que ha terminado*/
		pidC = wait(&status);
		printf("PADRE de PID = %d, hijo de PID = %d terminado, status de hijo = %d\n", getpid(), pidC, WEXITSTATUS(status));
	}

	while(1)
	{
		/*El padre se queda en el bucle infinito*/
		sleep(10); /*asi el padre duerme para siempre*/
	}
	return(0);
}
