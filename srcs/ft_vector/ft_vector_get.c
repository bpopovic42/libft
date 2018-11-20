/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:28:23 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/20 04:31:30 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_get(t_vect *v, size_t index)
{
	if (index >= v->size)
		ft_perror("ft_vector_get: index out of bounds");
	return (v->data[index]);
}
