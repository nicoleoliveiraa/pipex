/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/12 15:21:01 by nsouza-o         ###   ########.fr       */
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
			return (env[i]);
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

char	**find_cmd_words(char *cmd)
{
	int	i;
	int words;
	char **cmd_words;

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
	cmd_words = separate_cmd(cmd, words, 0, 0, 0);
	return (cmd_words);	
}

bool	commands_management(char* cmd1, char *cmd2, char **env)
{
	char *path1;
	char	*path2;
	char **path_apart;
	char	**cmd_words1;
	char	**cmd_words2;

	path1 = find_path(env);
	path1 = &path1[5];
	path_apart = ft_split(path1, ':');
	cmd_words1 = find_cmd_words(cmd1);
	path1 = check_command(cmd_words1[0], path_apart);
	cmd_words2 = find_cmd_words(cmd2);
	path2 = check_command(cmd_words2[0], path_apart);
	ptr_free(path_apart);
	ptr_free(cmd_words1);
	ptr_free(cmd_words2);
	free(path1);
	free(path2);	
	return (true);
}
