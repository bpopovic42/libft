/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_freetable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:40:15 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/13 18:12:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hash_freetable(t_hash **t, size_t s, void (*d)(void *))
{
	size_t	i;
	t_hash	*ptr;

	i = 0;
	while (i < s)
	{
		if (t[i])
		{
			while (t[i] != NULL)
			{
				ptr = t[i]->next;
				ft_hashdel(t[i], d);
				t[i] = ptr;
			}
		}
		i++;
	}
	free(t);
}
