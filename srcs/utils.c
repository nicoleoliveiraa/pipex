/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:00:29 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/19 15:33:05 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	make_free(t_cmds *cmds)
{
	if (cmds->cmd)
	{
		free(cmds->cmd);
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
	if (!cmds->cmd || cmds->cmd[0][0] == '\0')
		perror("Error");
	exit(EXIT_FAILURE);	
}
