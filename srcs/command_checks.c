/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/16 18:10:12 by nsouza-o         ###   ########.fr       */
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
			return (temp_cmd);
		free(temp_cmd);
		i++;		
	}
	return (NULL);
}

char	*check_command(char *cmd, char **path_apart)
{
	char	*valid_path;
	
	cmd = ft_strjoin("/", cmd);
	valid_path = is_valid(cmd, path_apart);
	free(cmd);
	if (valid_path) 
		return (valid_path);
	else
		return (NULL);
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

void	find_cmd_words(char *cmd1, char *cmd2, t_cmds *cmds)
{
	int words;
	
	words = count_words(cmd1);
	cmds->cmd_1 = malloc(sizeof(char *) * (words + 1));
	cmds->cmd_1 = separate_cmd(cmd1, words, 0);
	words = count_words(cmd2);
	cmds->cmd_2 = malloc(sizeof(char *) * (words + 1));
	cmds->cmd_2 = separate_cmd(cmd2, words, 0);	
}

void	commands_management(char* cmd1, char *cmd2, char **env, t_cmds *cmds)
{
	char *path;
	char **path_apart;

	path = find_path(env);
	if (path)
		path_apart = ft_split(path, ':');
	find_cmd_words(cmd1, cmd2, cmds);
	if (!cmds->cmd_1 || !cmds->cmd_2)
		return ;
	cmds->path_1 = check_command(cmds->cmd_1[0], path_apart);
	cmds->path_2 = check_command(cmds->cmd_2[0], path_apart);
	ptr_free(path_apart);
	free(path);
}
