/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:07:17 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/05 19:32:46 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstpop(t_list *list)
{
	t_node *pop;

	if (list)
	{
		if (list->size == 0)
			return (NULL);
		pop = list->head;
		if (list->size == 1)
		{
			list->head = NULL;
			list->tail = NULL;
		}
		else
			list->head = list->head->next;
		list->size--;
		return (pop);
	}
	return (NULL);
}
