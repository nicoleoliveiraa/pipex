/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:23:05 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/24 18:06:31 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct	s_cmds
{
	char	*path;
	char	**cmd;
}	t_cmds;

typedef struct s_input
{
	char	*text;
}	t_input;

//command checks
char *find_path(char **env);
//char	*is_valid(char *cmd, char **path);
void	is_valid(char *cmd, char **path, t_cmds *cmds);
void	check_command(t_cmds *cmds, char **path_apart);
void	commands_management(char* cmd1, char **env, t_cmds *cmds);
void	find_cmd_words(char *cmd1, t_cmds *cmds);
void	separate_cmd(char *cmd, int words, t_cmds *cmds);

//execute
void	execute(t_cmds *cmds, char **env);
int	open_outfile(char *file);
int	open_infile(char *file, char **argv);
void	do_child_proc(t_cmds *cmds, char **env);

void	error(int exit_status);
void	make_free(t_cmds *cmds);
void	check_error(t_cmds *cmds);
void	clean_all(t_cmds *cmds);
void	put_right_error(t_cmds *cmds, char *message, int error);

#endif