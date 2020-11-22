/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:36:39 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/21 14:37:42 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char		*s;
	char			*d;
	size_t			i;

	i = 0;
	s = src;
	d = dest;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c)
		{
			i++;
			return (dest + i);
		}
	}
	return (NULL);
}