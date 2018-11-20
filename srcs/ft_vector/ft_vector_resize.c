/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:06:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/20 05:15:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vector_resize(t_vect *v)
{
	v->capacity *= 2;
	if (!(v->data = ft_realloc(v->data, v->data_size * v->size, v->data_size * v->capacity)))
		ft_perror("ft_vector_resize: resize failed");
}
