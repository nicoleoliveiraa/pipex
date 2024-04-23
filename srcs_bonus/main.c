/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/23 21:20:46 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_doc(char *limiter)
{
	
}

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int i;
	int infile;
	int outfile;
	
	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 6))
	{
		outfile = open_outfile(argv[argc - 1]);
		here_doc(argv[2]);
		i = 3;
	}
	else
	{
		infile = open_infile(argv[1], argv);
		outfile = open_outfile(argv[argc - 1]);
		dup2(infile, STDIN_FILENO);
		i = 2;
	}
	while (i < argc - 2)
	{
		commands_management(argv[i], env, &cmds);
		do_child_proc(&cmds, env);
		i++;
	}
	make_free(&cmds);
	commands_management(argv[i], env, &cmds);
	dup2(outfile, STDOUT_FILENO);
	execute(&cmds, env);
	return (0);
}

/* int main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	int i;
	
	if (argc < 5)
		return (1);
	i = 2;
	while (i <= argc - 2)
	{
		printf("%d\n", i);
		commands_management(argv[i], env, &cmds);
		printf("%s \n %s \n", cmds.cmd[0], cmds.path);
		if(cmds.cmd && cmds.path)
		do_child_proc(&cmds, env);
		clean_all(&cmds);
		i++;
	}
} */