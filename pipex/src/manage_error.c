#include "../include/pipex.h"

void manage_error(char * msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
