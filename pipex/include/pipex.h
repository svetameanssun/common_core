#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../libft/libft.h"

char *set_path(char **cmd, char **envp);
void pipex(int argc, char **argv, char **envp, int pipe_fd[2]);
void manage_error(char * msg);
char **manage_cmd(char *arg);
int main(int argc, char ** argv, char ** envp);


#endif