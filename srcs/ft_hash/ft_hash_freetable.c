/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_freetable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:40:15 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/30 16:46:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_freetable(t_htable **t, void (*d)(void *))
{
	size_t	i;
	t_hash	*ptr;

	i = 0;
	while (i < (*t)->size)
	{
		if ((*t)->table[i])
		{
			while ((*t)->table[i] != NULL)
			{
				ptr = (*t)->table[i]->next;
				ft_hashdel((*t)->table[i], d);
				(*t)->table[i] = ptr;
			}
		}
		i++;
	}
	free((*t)->table);
	free(*t);
}
