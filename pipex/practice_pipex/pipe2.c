#include <unistd.h>
#include <stdio.h>

int main()
{
	int id;
	int p1[2];
	int p2[2];
	
	pipe(p1);
	pipe(p2);

	id = fork();

	if(id > 0)
	{
		int x;
		close(p1[0]);
		close(p2[1]);
		printf("Introduce an integer:\n");
		scanf("%d", &x);
		write(p1[1], &x, sizeof(int));
		close(p1[1]);
		read(p2[0], &x, sizeof(int));
		printf("The result: %d\n", x);
		close(p2[0]);
	}
	if (id == 0)
	{
		int y;
		close(p1[1]);
		close(p2[0]);
		read(p1[0], &y, sizeof(int));
		y = y * 4;
		write(p2[1], &y, sizeof(int));
		close(p2[1]);
	}
	return(0);
}
