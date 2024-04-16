/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/15 21:20:37 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmds	*cmds;
	int pid;
	
	if (argc != 5)
		return (1);
	commands_management(argv[2], argv[3], env, cmds);
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
		execute(argv, env, cmds);
	else
		wait();
	return (0);
}