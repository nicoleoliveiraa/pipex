/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:00:29 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/26 18:51:24 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(int exit_status)
{
	perror("Error");
	exit(exit_status);
}

void	make_free(t_cmds *cmds)
{
	if (cmds->cmd)
	{
		ptr_free(cmds->cmd);
		cmds->cmd = NULL;
	}
	if (cmds->path)
	{
		free(cmds->path);
		cmds->path = NULL;
	}
}

void	check_error(t_cmds *cmds)
{
	if (cmds->cmd == NULL || cmds->path == NULL)
	{
		clean_all(cmds);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
}

void	clean_all(t_cmds *cmds)
{
	if (cmds->cmd)
		ptr_free(cmds->cmd);
	if (cmds->path)
		free(cmds->path);
	free(cmds);
}

void	put_right_error(t_cmds *cmds, char *message, int error)
{
	ft_putstr_fd(cmds->cmd[0], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	make_free(cmds);
	exit(error);
}
