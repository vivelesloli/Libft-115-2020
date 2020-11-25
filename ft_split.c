/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:36:25 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/25 02:39:21 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcnt(const char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		while (str[i] == c && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int		ft_wordlen(const char *str, char c)
{
	int len;

	len = 0;
	while (*str != c)
	{
		str++;
		len++;
	}
	return (len);
}

static char		**ft_copyover(char **output, const char *s, char c)
{
	int		j;
	int		k;

	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			continue ;
		output[j] = malloc(sizeof(char*) * ft_wordlen(s, c) + 1);
		if (output[j] == NULL)
			return (NULL);
		k = 0;
		while (*s != c && *s != '\0')
		{
			output[j][k] = *s;
			k++;
			s++;
		}
		output[j][k] = '\0';
		j++;
	}
	output[j] = NULL;
	return (output);
}

char			**ft_split(const char *s, char c)
{
	char	**output;

	output = malloc(sizeof(char*) * (ft_wordcnt(s, c) + 1));
	if (s == NULL || output == NULL)
		return (NULL);
	output = ft_copyover(output, s, c);
	return (output);
}
