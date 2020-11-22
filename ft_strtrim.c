/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:32:56 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/22 16:33:04 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checktrim(char c, char const *set)
{
	int k;

	k = 0;
	while (set[k])
	{
		if (set[k] == c)
			return (1);
		k++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		begin;
	int		end;

	begin = 0;
	end = ft_strlen(s1) - 1;
	while (ft_checktrim(s1[begin], set) == 1)
		begin++;
	if ((begin - 1) == end)
	{
		res = malloc(1);
		res[0] = 0;
		return (res);
	}
	while (ft_checktrim(s1[end], set) == 1)
		end--;
	res = ft_substr(s1, begin, (end - begin + 1));
	return (res);
}
