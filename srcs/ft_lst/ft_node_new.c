/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 18:59:31 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/13 21:04:26 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node	*ft_node_new(void const *data, size_t data_size)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	if (data == NULL)
	{
		new->data = NULL;
		new->data_size = 0;
	}
	else
	{
		if (!(new->data = ft_memdup(data, data_size)))
			return (NULL);
		new->data_size = data_size;
	}
	return (new);
}
