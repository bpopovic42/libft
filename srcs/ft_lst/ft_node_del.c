/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:15:45 by bopopovi          #+#    #+#             */
/*   Updated: 2019/05/20 16:11:33 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_node_del(t_node **node, void (*del)(void *, size_t))
{
	if (node)
	{
		if (del)
			del(((*node)->data), (*node)->data_size);
		free(*node);
		*node = NULL;
	}
}
