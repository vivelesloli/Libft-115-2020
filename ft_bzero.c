/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:26:55 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/19 17:27:05 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned long		i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	if (len <= 0)
		return ;
	while (i < len)
	{
		ptr[i++] = '\0';
	}
}
