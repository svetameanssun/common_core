#include "../include/pipex.h"
#include "../libft/libft.h"

void manage_error(char * msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
