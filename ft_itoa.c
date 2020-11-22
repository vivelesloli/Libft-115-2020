/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:38:09 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/22 16:38:19 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_swap(char *s)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	if (s[0] == '-')
		start++;
	end = ft_strlen(s) - 1;
	tmp = 0;
	while (end > start)
	{
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		end--;
		start++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	nbr;

	nbr = n;
	res = (char*)malloc(sizeof(char) * 12);
	if (res == 0)
		return (0);
	i = 0;
	if (nbr < 0)
	{
		res[i] = '-';
		nbr = -nbr;
		i++;
	}
	if (nbr == 0)
		res[i++] = 48;
	while (nbr >= 1)
	{
		res[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i++;
	}
	res[i] = '\0';
	return (ft_swap(res));
}
