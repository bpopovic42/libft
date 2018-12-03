/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:52:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:16:19 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dictpop(t_dict **list, int key)
{
	t_dict	*ptr;
	t_dict	*node;

	if (*list)
	{
		ptr = *list;
		node = ptr;
		while (ptr)
		{
			if (ptr->key == key)
			{
				if (ptr == *list)
					*list = (*list)->next;
				else
				{
					while (node->next != ptr)
						node = node->next;
					node->next = ptr->next;
				}
				return (ptr);
			}
			ptr = ptr->next;
		}
	}
	return (NULL);
}
