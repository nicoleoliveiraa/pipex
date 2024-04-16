/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:00:00 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/16 17:49:27 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_cmds	cmds;
	
	if (argc != 5)
		return (1);
	commands_management(argv[2], argv[3], env, &cmds);
	//execute(argv, env, cmds);
	return (0);
}