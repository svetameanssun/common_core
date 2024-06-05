/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:16 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/05 15:50:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include "../libft/libft.h"

int		main(int argc, char **argv, char **envp);
char	**manage_cmd(char *arg);
void	manage_error(char *msg);
void	pipex(char **argv, char **envp, int pipe_fd[2]);
char	*set_path(char **cmd, char **envp);

#endif