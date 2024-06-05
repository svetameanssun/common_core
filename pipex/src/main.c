/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:26 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/05 15:45:42 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipe_fd[2];

	if (argc == 5)
	{
		if (pipe(pipe_fd) == -1)
			manage_error("Could not create pipe");
		else
			pipex(argv, envp, pipe_fd);
	}
	else
		manage_error("Wrong number of arguments");
}
