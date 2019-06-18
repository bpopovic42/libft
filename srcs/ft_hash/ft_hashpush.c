/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:04:55 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/18 21:46:39 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashpush(t_htable *table, t_hash *elem)
{
	int		hash;
	t_hash	*ptr;

	hash = ft_hash(table, elem->key);
	if (table->table[hash] == NULL)
		table->table[hash] = elem;
	else
	{
		ptr = table->table[hash];
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = elem;
	}
}
