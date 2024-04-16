/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:44:47 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/15 21:04:59 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_child_proc(char **env, t_cmds *cmds, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(cmds->path_1, cmds->cmd_1, env) == -1)
		error();
}

void	do_parent_proc(char **env, t_cmds *cmds, int *fd)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(file_2, STDOUT_FILENO);
	if (execve(cmds->path_2, cmds->cmd_2, env) == -1)
		error();
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	return (fd);
}

void	execute(char **argv, char **env, t_cmds *cmds)
{
	int	fd[2];
	int proc_id;
	int file_1;
	int file_2;
	
	file_1 = open_file(argv[1]);
	file_2 = open_file(argv[4]);
	dup2(file_1, STDIN_FILENO);
	if (pipe(fd) == -1)
		error();
	proc_id = fork();
	if (proc_id == -1)
		error();
	else if (proc_id == 0)
		do_child_proc(env, cmds, file_1, fd);
	else 
	{
		waitpid(proc_id, NULL, 0);
		do_parent_proc(env, cmds);
	}
	close(file_1);
	close(file_2);
}