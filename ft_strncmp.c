/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:39:10 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/18 18:34:37 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if ((unsigned char)s1[i] == (unsigned char)s2[i] || n == 0)
		return (0);
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
			&& i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
