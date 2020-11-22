/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:51:43 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/21 14:52:09 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cp1;
	unsigned char	*cp2;
	size_t			i;

	i = 0;
	cp1 = (unsigned char *)s1;
	cp2 = (unsigned char *)s2;
	while (i < n)
	{
		if (cp1[i] != cp2[i])
			return (cp1[i] - cp2[i]);
		i++;
	}
	return (0);
}
