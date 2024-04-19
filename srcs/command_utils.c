/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 21:08:58 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/19 15:42:41 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**separate_cmd(char *cmd, int words)
{
	char	**cmd_words;
	int	i;
	int j;
	int k;

	cmd_words = malloc(sizeof(char *) * (words + 1));
	if(!cmd_words)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while(words > j)
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == 39))
			i++;
		k = i;
		while (cmd[i] && cmd[i] != ' ')
			i++;
		cmd_words[j] = ft_substr(cmd + k, 0, (i - k));
		j++;
	}
	cmd_words[j] = NULL;
	return (cmd_words);
}
