/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:44:47 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/18 22:44:22 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_child_proc(t_cmds *cmds, char **env)
{
	int proc_id;
	int fd[2];

	if(pipe(fd) == -1)
		error();
	proc_id = fork();
	if (proc_id == -1)
		error();
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
	int fd;
	
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		error();
	return (fd);
}

int	open_infile(char *file)
{
	int fd;
	
	fd = open(file, O_RDONLY, 0444);
	if (fd < 0)
		error();
	return (fd);
}

void	execute(t_cmds *cmds, char **env)
{
	if (execve(cmds->path, cmds->cmd, env) == -1)
		error();
}