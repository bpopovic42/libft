/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:08:41 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:25:39 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush_back(t_list *list, t_node *node)
{
	if (list)
	{
		if (list->size == 0)
		{
			list->head = node;
			list->tail = node;
		}
		else
		{
			list->tail->next = node;
			list->tail = list->tail->next;
		}
		list->size++;
	}
}
