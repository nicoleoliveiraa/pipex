/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:23:05 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/18 21:52:42 by nsouza-o         ###   ########.fr       */
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
# include "./libft/libft.h"

typedef struct	s_cmds
{
	char	*path;
	char	**cmd;
}	t_cmds;


//command checks
char *find_path(char **env);
char	*is_valid(char *cmd, char **path);
void	check_command(t_cmds *cmds, char **path_apart);
void	commands_management(char* cmd1, char **env, t_cmds *cmds);
void	find_cmd_words(char *cmd1, t_cmds *cmds);
char	**separate_cmd(char *cmd, int words);

//execute
void	execute(t_cmds *cmds, char **env);
int	open_outfile(char *file);
int	open_infile(char *file);
void	do_child_proc(t_cmds *cmds, char **env);

void	error(void);

#endif