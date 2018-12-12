/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_newtable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:56:32 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/12 19:33:14 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_htable	*ft_hash_newtable(size_t table_size)
{
	t_htable	*new;
	size_t		i;

	i = 0;
	if (!(new = malloc(sizeof(*new))))
		ft_perror("ft_hash_newtable : Couldn't allocate structure.");
	new->size = table_size;
	if (!(new->table = malloc(sizeof(t_hash) * table_size)))
		ft_perror("ft_hash_newtable : Couldn't allocate table.");
	while (i < table_size)
		new->table[i++] = NULL;
	return (new);
}
