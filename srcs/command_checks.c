/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:17:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/11 21:34:52 by nsouza-o         ###   ########.fr       */
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

char	**is_valid(char *cmd, char **path)
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

bool	check_command(char *cmd1, char *cmd2, char **env)
{
	char *path;
	char **path_apart;
	char	*valid_path1;
	char	*valid_path2;
	
	path = find_path(env);
	path = &path[5];
	path_apart = ft_split(path, ':');
	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	valid_path1 = is_valid(cmd1, path_apart);
	valid_path2 = is_valid(cmd2, path_apart);
	free(cmd1);
	free(cmd2);
	ptr_free(path_apart);
	if (valid_path1 && ) //fazer um de cada vez pq precisa retornar o comando;
		return (true);
	else
		return (false);
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
	int i = -1;
	char **a = find_cmd_words(cmd1);
	printf("%s\n", cmd1);
	while (a[++i])
		printf("%s\n", a[i]);
	char **b = find_cmd_words(cmd2);
	i = -1;
	while (b[++i])
		printf("%s\n", b[i]);
	if (check_command(a[0], b[0], env))
		printf("valids commands\n");
	else 
		printf("invalids commands\n");	
	return (true);
}