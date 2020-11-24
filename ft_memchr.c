/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 14:42:25 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/24 09:20:59 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		chr;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	chr = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (*(ptr + i) == chr)
			return (ptr + i);
	return (NULL);
}
