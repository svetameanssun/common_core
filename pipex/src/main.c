#include "../include/pipex.h"

int main(int argc, char **argv, char **envv)
{
	int	pipe_fd[2];
	int	i;

	i = 1;
	while(i < argc)
	{
		if(argv[1][0] == '\0' || argv[1] == NULL || argv[1][0] == ' ')
			manage_error("Command not found");
		i++;
	}
	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			manage_error("Could not create pipe");
		else
			ft_fork(argv, envv, pipe_fd);
	}
	else
		manage_error("Wrong number of args");
	return(0);
}
