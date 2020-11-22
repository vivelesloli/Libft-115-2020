/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 15:04:56 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/21 15:05:46 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		buffer[n];
	char		*destcpy;
	char		*source;

	source = (unsigned char *)src;
	destcpy = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		buffer[i] = source[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		destcpy[i] = buffer[i];
		i++;
	}
	return (dest);
}
