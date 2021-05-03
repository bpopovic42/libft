/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstapply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:07:27 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:07:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies function 'apply' to all list nodes
** Returns EXIT_FAILURE if 'apply' does not return successfully
** Returns EXIT_SUCCESS otherwise
*/

int	ft_lstapply(t_list *lst, int (apply)(t_node *node))
{
	t_node *node_ptr;

	node_ptr = lst->head;
	while (node_ptr)
	{
		if (apply(node_ptr) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		node_ptr = node_ptr->next;
	}
	return (EXIT_SUCCESS);
}
