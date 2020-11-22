/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:09:32 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/18 18:34:37 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (const char*)s;
	while (*str != '\0')
		if (*str == c)
			return (str);
		else
			str++;
	if (c == '\0')
		return (str);
	return (NULL);
}
