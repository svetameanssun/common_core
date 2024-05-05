#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc,char ** argv)
{
	int id;
	int fd[2];

	pipe(fd);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Introduce and integer: \n");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		y = y * 2;
		printf("%d\n", y);
	}
	printf("%d\n",fd[0]);
	printf("%d\n", fd[1]);

	return(0);
}
