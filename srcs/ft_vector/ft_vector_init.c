/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 02:50:01 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/30 19:22:00 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vect	*ft_vector_init(size_t data_size, size_t capacity)
{
	t_vect *new;

	if (!(new = malloc(sizeof(t_vect))))
		ft_perror("ft_vector_init: vector allocation failed.");
	if (capacity == 0)
		capacity = VECTOR_INITIAL_SIZE;
	else
		new->capacity = capacity;
	if (!(new->data = malloc(data_size * capacity)))
		ft_perror("ft_vector_init: vector data's allocation failed.");
	new->data_size = data_size;
	new->size = 0;
	return (new);
}
