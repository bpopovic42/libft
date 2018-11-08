/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:01:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 14:00:25 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*tmp;
	t_dlist	*ptr;

	if (alst)
	{
		if (*alst && elem)
		{
			ptr = *alst;
			while (ptr->next && ptr->next != *alst)
				ptr = ptr->next;
			tmp = ptr->next;
			ptr->next = elem;
			elem->prev = ptr;
			elem->next = tmp;
			if (tmp)
				tmp->prev = tmp;
		}
		else
			*alst = elem;
	}
}
