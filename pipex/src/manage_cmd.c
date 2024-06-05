/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:30 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/05 15:46:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**manage_cmd(char *arg)
{
	char	**cmd_args;

	if (!ft_strncmp(arg, "awk", 3))
	{
		if (arg[4] == '\'')
			cmd_args = ft_split(arg, '\'');
		if (arg[4] == '\"')
			cmd_args = ft_split(arg, '\"');
		cmd_args[0] = ft_strtrim(cmd_args[0], " ");
	}
	else
		cmd_args = ft_split(arg, ' ');
	if (cmd_args == NULL)
		manage_error("Error splitting command");
	return (cmd_args);
}