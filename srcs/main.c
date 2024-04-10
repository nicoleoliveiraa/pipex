/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/10 19:03:37 by nsouza-o         ###   ########.fr       */
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

bool	check_command(char *cmd1, char *cmd2, char **env)
{
	char *path;
	char **path_apart;
	int i = 0;
	
	path = find_path(env);
	path = &path[5];
	path_apart = ft_split(path, ':');
	cmd1 = ft_strjoin("/", cmd1);
	cmd2 = ft_strjoin("/", cmd2);
	while (path_apart[i])
	{
		cmd1 = ft_strjoin(path_apart[i], cmd1);
		cmd2 = ft_strjoin(path_apart[i], cmd2);
		printf("%s\n", cmd1);
		printf("%s\n", cmd2);
		i++;
	}	
	return (true);
/* 	
	printf("%s %s \n", cmd1, cmd2);
	while (path_apart[i])
	{
		printf("%s\n", path_apart[i]);
		i++;
	}
	return (true);
	access("jhijkj00", F_OK )	 */
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 5)
		return (1);
	check_command(argv[2], argv[3], env);
	return (0);
}