/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:06:50 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/04 15:12:53 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_vector_resize(t_vect *v)
{
	size_t	new_size;
	size_t	current_size;

	current_size = (v->data_size * v->size);
	new_size = (v->data_size * (v->capacity * 2));
	if (ft_realloc((void**)&v->data, current_size, new_size) < 0)
	{
		ft_perror("ft_vector_resize: couldn't allocate new block.");
		return (-1);
	}
	v->capacity *= 2;
	return (0);
}
