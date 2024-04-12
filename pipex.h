/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:23:05 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/11 21:16:59 by nsouza-o         ###   ########.fr       */
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
# include "./libft/libft.h"

//command checks
char *find_path(char **env);
bool	is_valid(char *cmd, char **path);
bool	check_command(char *cmd1, char *cmd2, char **env);
bool	commands_management(char* cmd1, char *cmd2, char **env);
char	**find_cmd_words(char *cmd);
char	**separate_cmd(char *cmd, int words, int i, int j, int k);

#endif