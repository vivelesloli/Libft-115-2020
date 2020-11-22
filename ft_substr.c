/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:41:44 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/22 14:41:58 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;

	if (s == NULL)
		return (NULL);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	if (!(start > ft_strlen(s)))
	{
		while (i < len && s[i + start])
		{
			dest[i] = s[i + start];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
