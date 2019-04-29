/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:12:29 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/29 14:53:06 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnode_remove(t_list *list, t_node *target)
{
	t_node *ptr;

	ptr = NULL;
	if (list && target)
	{
		if (target == list->head)
			ft_lstpop(list);
		else
		{
			ptr = list->head;
			while (ptr->next && ptr->next != target)
				ptr = ptr->next;
			if (ptr->next == target)
			{
				if (target == list->tail)
					list->tail = ptr;
				ptr->next = target->next;
				target->next = NULL;
				list->size--;
			}
		}
	}
}
