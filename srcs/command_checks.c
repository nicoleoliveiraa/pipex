/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/18 22:33:55 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char *find_path(char **env)
{
	int i;
	
	i = 0;
	while(env[i])
	{
		if(!ft_strncmp(env[i], "PATH=", 5))	
			return (env[i] + 5);
		else
			i++;
	}
	return (NULL);
}

char	*is_valid(char *cmd, char **path)
{
	char *temp_cmd;
	int	i;
	
	i = 0;
	while (path[i])
	{
		temp_cmd = ft_strjoin(path[i], cmd);
		if (!access(temp_cmd, F_OK))
		{
			return (temp_cmd);
		}
		free(temp_cmd);
		i++;		
	}
	return (NULL);
}

void	check_command(t_cmds *cmds, char **path_apart)
{
	char *cmd;
	
	cmd = ft_strjoin("/", cmds->cmd[0]);
	cmds->path = is_valid(cmd, path_apart);
	free(cmd);
}

int	count_words(char *cmd)
{
	int	i;
	int words;
	
	if (!cmd)
		return (0);
	i = 0;
	words = 1;
	while(cmd[i])
	{
		if (cmd[i] == ' ' && cmd[i + 1])
		{
			if(cmd[i + 1] && cmd[i + 1] != ' ')
				words++;
		}
		i++;
	}
	return (words);
}

void	find_cmd_words(char *cmd1, t_cmds *cmds)
{
	int words;
	
	words = count_words(cmd1);
	cmds->cmd = malloc(sizeof(char *) * (words + 1));
	cmds->cmd = separate_cmd(cmd1, words);
}

void	commands_management(char* cmd1, char **env, t_cmds *cmds)
{
	char *path;
	char **path_apart;

	path = find_path(env);
	if (path)
		path_apart = ft_split(path, ':');
	find_cmd_words(cmd1, cmds);
	if (!cmds->cmd)
		error();
	check_command(cmds, path_apart);
	ptr_free(path_apart);
	//free(path);
}
