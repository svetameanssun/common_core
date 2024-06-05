/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:38 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/05 14:47:01 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void ft_child(char **argv, char **envp, int infile_fd, int pipe_fd[2])
{
    close(pipe_fd[0]);
    char * path = set_path(manage_cmd(argv[2]), envp);
    char **cmd = manage_cmd(argv[2]);
    write(2, *cmd, 3);
    if (dup2(infile_fd, STDIN_FILENO) == -1)
        manage_error("Redirection from STDIN to INFILE failed");
    if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
        manage_error("Redirection from STDOUT to PIPE[0] failed");
    close(pipe_fd[1]);
    close(infile_fd);
    execve(path, cmd, envp);
}

static void ft_parent(char **argv, char **envp, int outfile_fd, int pipe_fd[2])
{
    //int status;

    waitpid(0, NULL, 0);
    close(pipe_fd[1]);
    char * path = set_path(manage_cmd(argv[3]), envp);
    char **cmd = manage_cmd(argv[3]);
    if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
        manage_error("Redirection from STDIN to PIPE[1] failed");
    if (dup2(outfile_fd, STDOUT_FILENO) == -1)
        manage_error("Redirection from STDOUT to OUTFILE failed");
    close(pipe_fd[0]);
    close(outfile_fd);
    execve(path, cmd, envp);
}


void pipex(char **argv, char **envp, int pipe_fd[2])
{
    int pid;
    int infile_fd;
    int outfile_fd;
    
    infile_fd = open(argv[1], O_RDONLY, 0444);
    outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (infile_fd  == -1 || outfile_fd == -1)
        manage_error("Cound not open file");
    pid = fork();
    if (pid == -1)
        manage_error("Error forking");
    if (pid == 0)
        ft_child(argv, envp, infile_fd, pipe_fd);
    ft_parent(argv, envp, outfile_fd, pipe_fd);
}
