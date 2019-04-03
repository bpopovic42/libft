/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:07:17 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:12:58 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_lstpop(t_list *list)
{
	t_node *pop;

	if (list)
	{
		pop = list->head;
		list->head = list->head->next;
		list->size--;
		return (pop);
	}
	return (NULL);
}
