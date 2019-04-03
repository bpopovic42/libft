/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:11:38 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:12:07 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*ft_node_dup(t_node *node)
{
	t_node *new;

	if (node)
	{
		if (!(new = ft_node_new(node->data, node->data_size)))
			return (NULL);
		return (new);
	}
	return (NULL);
}
