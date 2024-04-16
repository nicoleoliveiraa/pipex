/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:23:05 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/16 18:05:05 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct	s_cmds
{
	char	*path_1;
	char	*path_2;
	char	**cmd_1;
	char	**cmd_2;
}	t_cmds;


//command checks
char *find_path(char **env);
char	*is_valid(char *cmd, char **path);
char	*check_command(char *cmd, char **path_apart);
void	commands_management(char* cmd1, char *cmd2, char **env, t_cmds *cmds);
void	find_cmd_words(char *cmd1, char *cmd2, t_cmds *cmds);
char	**separate_cmd(char *cmd, int words, int k);

//execute
void	execute(char **argv, char **env, t_cmds *cmds);
int	open_file(char *file);
void	do_parent_proc(char **env, t_cmds *cmds, int outfile, int *fd);
void	do_child_proc(char **env, t_cmds *cmds, int infile, int *fd);

void	error(void);

#endif