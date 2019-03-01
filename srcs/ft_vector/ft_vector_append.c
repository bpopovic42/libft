/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:20:57 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/01 00:21:39 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** UNSAFE : No form of malloc protection
*/

void	ft_vector_append(t_vect *v, void *value)
{
	if (v->size == v->capacity)
		ft_vector_resize(v);
	v->data[v->size] = value;
	v->size++;
}
