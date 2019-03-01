/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:05:35 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/01 15:38:40 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_free(t_vect *v, void (*del)(void **, size_t))
{
	size_t data_elems;

	data_elems = 0;
	while (data_elems < v->size)
	{
		del(&v->data[data_elems], v->data_size);
		data_elems++;
	}
	free(v->data);
	free(v);
}
