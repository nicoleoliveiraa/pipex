/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsouza-o <nsouza-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:09:22 by nsouza-o          #+#    #+#             */
/*   Updated: 2023/10/07 13:48:04 by nsouza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

/* #include <ctype.h>
#include <stdio.h>

int main(void)
{
	int c;

	c = '6';
	printf("%d\n", isprint(c));
	printf("%d\n", ft_isprint(c));
} */