/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/23 19:10:04 by nsouza-o         ###   ########.fr       */
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

/* char	*is_valid(char *cmd, char **path)
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
} */

void	is_valid(char *cmd, char **path, t_cmds *cmds)
{
	int	i;
	
	i = 0;
	while (path[i])
	{
		free(cmds->path);
		cmds->path = ft_strjoin(path[i], cmd);
		if (!access(cmds->path, F_OK))
		{
			return ;
		}
		i++;		
	}
}

void	check_command(t_cmds *cmds, char **path_apart)
{
	char *cmd;
	
	cmd = ft_strjoin("/", cmds->cmd[0]);
	is_valid(cmd, path_apart, cmds);
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
	
	if (cmd1[0] == '\0')
	{
		cmds->cmd = NULL;
		return ;
	}
	if (!cmd1)
	{
		cmds->cmd = NULL;
		return ;
	}
	words = count_words(cmd1);
	separate_cmd(cmd1, words, cmds);
}

void	commands_management(char* cmd1, char **env, t_cmds *cmds)
{
	char *path;
	char **path_apart;

	path_apart = NULL;
	path = find_path(env);
	if (path)
		path_apart = ft_split(path, ':');
	find_cmd_words(cmd1, cmds);
	if (cmds->cmd[0][0] == '/')
		cmds->path = ft_strdup(cmds->cmd[0]);
	else if (cmds->cmd)
		check_command(cmds, path_apart);
	ptr_free(path_apart);
}
