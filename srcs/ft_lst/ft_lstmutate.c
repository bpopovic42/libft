/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmutate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:06:40 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:06:51 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Creates a new list, which nodes results from applying the 'mut' function
** to each of the original list's nodes
** Returns EXIT_FAILURE if 'mut' does not return successfully
** Returns EXIT_SUCCESS otherwise
*/

int		ft_lstmutate(t_list *src, t_list *dst,
			int (mut)(t_node *src, t_node **dst))
{
	t_node *node_ptr;
	t_node *result_node;

	node_ptr = src->head;
	while (node_ptr)
	{
		result_node = NULL;
		if (mut(node_ptr, &result_node) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (result_node != NULL)
			ft_lstadd(dst, result_node);
		node_ptr = node_ptr->next;
	}
	return (EXIT_SUCCESS);
}
