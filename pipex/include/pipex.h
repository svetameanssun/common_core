#ifndef PIPEX_H
#define PIPEX_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../libft/libft.h"


#define READ 0
#define WRITE 1

int main(int argc, char **argv, char **envv);
void manage_error(char * msg);
int char_count(int c, char *str);
void ft_fork(char ** argv, char ** envv, int *pipe_fd);

void start_child_one(char ** argv, char **envv, int *pipe_fd);
void start_child_two(char ** argv, char **envv, int *pipe_fd);


#endif
