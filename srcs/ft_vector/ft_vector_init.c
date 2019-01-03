/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 02:50:01 by bopopovi          #+#    #+#             */
/*   Updated: 2019/01/03 21:19:38 by bopopovi         ###   ########.fr       */
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
	new->capacity = capacity;
	if (!(new->data = malloc(data_size * new->capacity)))
		ft_perror("ft_vector_init: vector data's allocation failed.");
	ft_bzero(new->data, data_size * new->capacity);
	new->data_size = data_size;
	new->size = 0;
	return (new);
}
