/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:04:56 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/24 15:19:18 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	char				buffer[len];
	unsigned char		*destcpy;
	unsigned char		*source;

	source = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < len)
	{
		buffer[i] = source[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		destcpy[i] = buffer[i];
		i++;
	}
	return (dest);
}
