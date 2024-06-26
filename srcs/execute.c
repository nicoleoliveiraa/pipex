/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:44:47 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/27 18:16:17 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_child_proc(t_cmds *cmds, char **env)
{
	int	proc_id;
	int	fd[2];

	if (pipe(fd) == -1)
		error(1);
	proc_id = fork();
	if (proc_id == -1)
		error(1);
	if (proc_id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(cmds, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(proc_id, NULL, 0);
	}
}

int	open_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	return (fd);
}

int	open_infile(char *file, char **argv)
{
	int	fd;

	fd = open(file, O_RDONLY, 0444);
	if (fd < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		perror(argv[1]);
		exit(0);
	}
	return (fd);
}

void	execute(t_cmds *cmds, char **env)
{
	if (!cmds->cmd)
	{
		ft_putstr_fd("command not found\n", 2);
		make_free(cmds);
		exit(1);
	}
	if (execve(cmds->path, cmds->cmd, env) == -1)
	{
		put_right_error(cmds, "command not found", 127);
	}
}
