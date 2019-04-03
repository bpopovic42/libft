/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:08:09 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:12:30 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstdup(t_list *list)
{
	t_node	*ptr;
	t_node	*node_dup;
	t_list	*list_dup;

	if (list)
	{
		ptr = list->head;
		if (!(list_dup = ft_lstnew()))
			return (NULL);
		while (ptr)
		{
			if (!(node_dup = ft_node_dup(ptr)))
				return (NULL);
			ft_lstpush_back(list_dup, node_dup);
			ptr = ptr->next;
		}
		return (list_dup);
	}
	return (NULL);
}
