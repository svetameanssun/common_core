/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:50 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/05 15:39:38 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	**find_path(char **envp)
{
	char	*full_path;
	char	**split_paths;

	full_path = NULL;
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			full_path = *envp + 5;
			break ;
		}
		envp++;
	}
	split_paths = ft_split(full_path, ':');
	return (split_paths);
}

char	*set_path(char **cmd, char **envp)
{
	char	*path;
	char	**split_paths;

	split_paths = find_path(envp);
	while (*split_paths)
	{
		path = ft_strjoin(ft_strjoin(*split_paths, "/"), cmd[0]);
		if (path == NULL)
			manage_error("Error joining path's elements");
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		split_paths++;
	}
	return (path);
}
