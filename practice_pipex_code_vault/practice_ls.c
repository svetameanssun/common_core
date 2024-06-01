#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

#define READ_END 0   /*  index pipe extremo lectura */
#define WRITE_END 1   /*  index pipe extremo escriture */

#define FILE_NAME "file.txt"

int main(int argc, char **argv)
{
	int pid;  /*el identificador de proceso de los hijos*/
	int status; /*para realizar el wait quehace el padre para cada uno
		      de sus hijos*/
	int fd2;  /*file descriptor que correspone al archivo file.txt*/
	int fd1[2]; /* array de 2 posisiones, array de 2 filedescriptors (fd de
		      lectura, fd deescritutra)*/

	pipe(fd1); 			/* comunica ls y wc */
	
	pid = fork();			/* creamos el primer hijo */
	if(pid == 0)			/*hijo 1, ejecuta "ls -l"*/
	{
		close(fd1[READ_END]);		/*cerrar extremos no necesarios del pipe*/
		dup2(fd1[WRITE_END], STDOUT_FILENO);
		close(fd1[WRITE_END]);

		execlp("/bin/ls", "ls", NULL);	
	}
	else				/*padre*/
	{
		close(fd1[WRITE_END]);
		pid = fork();		/*hijo 2, ejecuta "wc"*/
		if (pid == 0)
		{
			fd2 = open(FILE_NAME, O_WRONLY);
			dup2(fd1[READ_END], STDIN_FILENO);
			close(fd1[READ_END]);

			dup2(fd2, STDOUT_FILENO);
			execlp("/usr/bin/wc", "wc", NULL);
		}
		else/*padre*/
		{
			close(fd1[READ_END]);	/*CERRAR EXTREMO NO NECESARIO*/
		}

	}
	/* wait para cada hijo */
	wait(&status);
	wait(&status);
	return(0);
}
