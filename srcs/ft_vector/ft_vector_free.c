/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:05:35 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/23 01:44:15 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_free(t_vect *v, void (*del)(void **))
{
	size_t data_elems;

	data_elems = 0;
	while (data_elems < v->size)
	{
		del(&v->data[data_elems]);
		data_elems++;
	}
	free(v->data);
	free(v);
}
