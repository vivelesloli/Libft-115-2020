/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 08:53:27 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/24 09:51:23 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		end;

	end = 0;
	i = 0;
	while (i < n)
	{
		end = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (end != 0 || !s1[i] || !s2[i])
			return (end);
		i++;
	}
	return (end);
}
