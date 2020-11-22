/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:54:47 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/19 15:54:52 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	*last;

	str = (char*)s;
	last = NULL;
	while (*str != '\0')
	{
		if (*str == c)
			last = str;
		str++;
	}
	if (c == '\0')
		return (str);
	return (last);
}
