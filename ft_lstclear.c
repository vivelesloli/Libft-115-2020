/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnavone <cnavone@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 01:30:54 by cnavone           #+#    #+#             */
/*   Updated: 2020/11/25 01:31:00 by cnavone          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

 #include "libft.h"
    
    void        ft_lstclear(t_list **lst, void (*del)(void *))
    {
        t_list  *curr;
        t_list  *next;
    
        curr = *lst;
        while (curr)
        {
            next = curr->next;
            ft_lstdelone(curr, del);
            curr = next;
        }
        *lst = NULL;
    }
	