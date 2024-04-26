/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:35:08 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/26 19:18:34 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

bool	is_here_doc(char **argv)
{
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		here_doc(argv[2]);
		return (true);
	}
	return (false);
}

void	do_parent_proc(char **argv, char **env, t_cmds *cmds)
{
	int	proc_id;

	proc_id = fork();
	if (proc_id == -1)
		error(1);
	if (proc_id == 0)
	{
		make_free(cmds);
		commands_management(argv[cmds->i], env, cmds);
		dup2(cmds->outfile, STDOUT_FILENO);
		execute(cmds, env);
	}
	make_free(cmds);
}

void	pipex(int argc, char **argv, char **env, t_cmds *cmds)
{
	while (cmds->i < argc - 2)
	{
		commands_management(argv[cmds->i], env, cmds);
		do_child_proc(cmds, env);
		cmds->i++;
	}
	do_parent_proc(argv, env, cmds);
}

void	here_doc_child(char *limiter, t_input *input, int fd_0, int fd_1)
{
	close(fd_0);
	while (1)
	{
		get_input(input);
		if (!ft_strncmp(input->text, limiter, ft_strlen(input->text)))
		{
			free(limiter);
			free(input->text);
			close(fd_1);
			exit(0);
		}
		write(fd_1, input->text, (ft_strlen(input->text)));
		free(input->text);
	}
}
