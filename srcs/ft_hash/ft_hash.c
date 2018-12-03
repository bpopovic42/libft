/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:37:11 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:21:13 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int		ft_hash(t_htable *table, char *key)
{
	unsigned long int	hash;
	int					i;

	i = 0;
	hash = 0;
	while (hash < ULONG_MAX && i < (int)ft_strlen(key))
	{
		hash <<= 8;
		hash += key[i];
		i++;
	}
	return ((int)(hash % table->size));
}
