/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_freetable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:40:15 by bopopovi          #+#    #+#             */
/*   Updated: 2019/01/04 14:38:00 by bopopovi         ###   ########.fr       */
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
			while ((*t)->table[i]->next != NULL)
			{
				ptr = (*t)->table[i]->next->next;
				ft_hashdel((*t)->table[i]->next, d);
				(*t)->table[i]->next = ptr;
			}
			ft_hashdel((*t)->table[i], d);
		}
		i++;
	}
	free((*t)->table);
	free(*t);
}
