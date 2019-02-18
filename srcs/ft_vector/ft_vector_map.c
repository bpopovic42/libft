/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:24:12 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/18 18:42:55 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_map(t_vect *v, void (*f)(void *))
{
	void	*data;
	size_t	i;

	data = NULL;
	i = 0;
	while (i < v->size)
	{
		data = ft_vector_get(v, i);
		f(data);
		i++;
	}
}
