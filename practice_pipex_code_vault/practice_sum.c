#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char ** argv)
{
	int sum = 0;
	int fd[2];
	int id;
	int arr[] = {1, 2, 3, 4, 5, 6};
	int start;
	int end;
	int arr_size = sizeof(arr)/sizeof(int);
	int i;

	pipe(fd);
	id = fork();
	if (id == -1)
		return(1);
	if (id == 0)
	{
		start = 0;
		end = arr_size/2;
	}
	else
	{
		start = arr_size/2;
		end = arr_size;
	}

	for(i = start; i < end; i++)
	{
		sum = sum + arr[i];
	}
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(int));
		close(fd[1]);
	}
	else
	{
		int child_sum;
		close(fd[1]);
		read(fd[0], &child_sum, sizeof(int));
		close(fd[0]);
		child_sum = child_sum + sum;
		printf("%d\n", child_sum);
	}
	return(0);
}
