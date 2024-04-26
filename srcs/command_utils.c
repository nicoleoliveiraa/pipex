/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:08:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/26 14:26:52 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	separate_cmd(char *cmd, int words, t_cmds *cmds)
{
	int	i;
	int	j;
	int	k;

	if (!cmd)
		return ;
	cmds->cmd = malloc(sizeof(char *) * (words + 1));
	if (!cmds->cmd)
		return ;
	i = 0;
	j = 0;
	k = 0;
	while (words > j)
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == 39))
			i++;
		k = i;
		while (cmd[i] && cmd[i] != ' ')
			i++;
		cmds->cmd[j] = ft_substr(cmd, k, (i - k));
		j++;
	}
	cmds->cmd[j] = NULL;
}

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		else
			i++;
	}
	return (NULL);
}
