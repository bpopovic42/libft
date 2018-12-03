/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:52:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 19:48:12 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash	*ft_hashpop(t_htable *table, char *key)
{
	int		hash;
	t_hash	*entry;
	t_hash	*ptr;

	hash = ft_hash(table, key);
	entry = ft_hashget(table, key);
	if (table->table[hash] == entry)
		table->table[hash] = entry->next;
	else
	{
		ptr = table->table[hash];
		while (ptr->next != entry && ptr->next != NULL)
			ptr = ptr->next;
		if (ptr->next == entry)
			ptr->next = entry->next;
		else if (!ptr->next)
			ft_perror("ft_hashpop : Couldn't find corresponding hash entry.");
	}
	return (entry);
}
