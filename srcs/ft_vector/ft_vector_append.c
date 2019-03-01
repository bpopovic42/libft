/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:20:57 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/01 16:12:57 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vector_append(t_vect *v, void *value)
{
	if (v->size == v->capacity)
	{
		if (ft_vector_resize(v) < 0)
			return (-1);
	}
	v->data[v->size] = value;
	v->size++;
	return (0);
}
