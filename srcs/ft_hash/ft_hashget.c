/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:52:12 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/25 20:37:32 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash	*ft_hashget(t_htable *table, char *key)
{
	int		hashed_key;
	t_hash	*hash_ptr;

	hash_ptr = NULL;
	if (table && key)
	{
		hashed_key = ft_hash(table, key);
		hash_ptr = table->table[hashed_key];
		while (hash_ptr)
		{
			if (!ft_strcmp(hash_ptr->key, key))
				return (hash_ptr);
			hash_ptr = hash_ptr->next;
		}
		hash_ptr = NULL;
	}
	return (NULL);
}
