/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:12:08 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 23:02:48 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpush(t_dlist **head, t_dlist *elem)
{
	if (elem)
	{
		if (*head)
		{
			elem->prev = (*head)->prev;
			elem->next = *head;
			if (elem->prev)
				elem->prev->next = elem;
			if (elem->next)
				elem->next->prev = elem;
		}
		else
		{
			elem->next = NULL;
			elem->prev = NULL;
		}
		*head = elem;
	}
}
