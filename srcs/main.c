/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/19 15:35:37 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int i;
	int infile;
	int outfile;
	
	if (argc < 5)
		return (1);
	i = 2;
	infile = open_infile(argv[1]);
	outfile = open_outfile(argv[argc - 1]);
	dup2(infile, STDIN_FILENO);
	while (i < argc - 2)
	{
		commands_management(argv[i], env, &cmds);
		do_child_proc(&cmds, env);
		i++;
	}
	dup2(outfile, STDOUT_FILENO);
	commands_management(argv[i], env, &cmds);
	execute(&cmds, env);
	return (0);
}
