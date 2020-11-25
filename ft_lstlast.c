/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:44:03 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/25 00:44:09 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstlast(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next)
		current = current->next;
	return (current);
}
