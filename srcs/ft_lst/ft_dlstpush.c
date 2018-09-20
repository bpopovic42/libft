/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 15:12:08 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/20 15:19:05 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstpush(t_dlist **head, t_dlist *elem)
{
	if (elem)
	{
		if (*head)
		{
			(*head)->prev = elem;
			elem->next = *head;
		}
		else
			elem->next = NULL;
		elem->prev = NULL;
		*head = elem;
	}
}
