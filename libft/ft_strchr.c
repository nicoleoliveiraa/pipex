/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:20:20 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 17:10:06 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str2;

	str2 = (char *)str;
	i = 0;
	while ((unsigned char)str[i] != (unsigned char)c)
	{
		if (!str[i])
			return (NULL);
		i++;
		str2++;
	}
	return (str2);
}
