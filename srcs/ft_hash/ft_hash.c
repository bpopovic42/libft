/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:37:11 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/29 17:13:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_hash(t_htable *table, char *key)
{
	unsigned long int	hash;
	int					key_size;
	int					i;

	i = 0;
	hash = 0;
	key_size = ft_strlen(key);
	while (hash < ULONG_MAX && i < key_size)
	{
		hash <<= 8;
		hash += key[i];
		i++;
	}
	return ((int)(hash % table->size));
}
