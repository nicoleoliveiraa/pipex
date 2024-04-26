/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:20:16 by nsouza-o          #+#    #+#             */
/*   Updated: 2024/04/26 16:01:28 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_counter(char *str, char c)
{
	int	i;
	int	indicator;
	int	nstr;

	i = 0;
	nstr = 0;
	while (str[i])
	{
		indicator = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			indicator = 1;
			i++;
		}
		while (str[i] == c && str[i])
			i++;
		if (indicator == 1)
			nstr++;
	}
	return (nstr);
}

static int	str_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

void	*ptr_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		nstr;
	int		i;

	if (!s)
		return (NULL);
	nstr = str_counter((char *)s, c);
	ptr = (char **)malloc((nstr + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	while (nstr > 0)
	{
		while (*s && *s == c)
			s++;
		ptr[i] = ft_substr(s, 0, str_len(s, c));
		if (!ptr[i])
			return (ptr_free(ptr));
		s = s + str_len(s, c);
		i++;
		nstr--;
	}
	ptr[i] = 0;
	return (ptr);
}
