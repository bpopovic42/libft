/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:01:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 13:50:14 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

void	ft_dlstinsert(t_dlist **alst, t_dlist *elem)
{
	t_dlist	*tmp;

	if (alst)
	{
		if (*alst && elem)
		{
			tmp = (*alst)->next;
			(*alst)->next = elem;
			elem->prev = *alst;
			elem->next = tmp;
			if (tmp)
				tmp->prev = tmp;
		}
		else
			*alst = elem;
	}
}
