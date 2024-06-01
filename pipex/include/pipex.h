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

int main(int argc, char **argv, char **envp);
void manage_error(char * msg);
int char_count(int c, char *str);
void ft_fork(char ** argv, char ** envp, int *pipe_fd);

void start_child_one(char ** argv, char **envp, int *pipe_fd);
void start_child_two(char ** argv, char **envp, int *pipe_fd);

char **get_splitted_paths(char ** envp);
char * get_cmd_path(char *arg, char ** envp);

void ft_exec(char *cmd_path, char *arg, char ** envp);
char **cmd_split(char *arg);
void ft_free_table(char **table);

#endif
