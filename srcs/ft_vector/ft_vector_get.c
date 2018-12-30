/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:28:23 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/30 19:30:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_get(t_vect *v, size_t index)
{
	if (!v || index >= v->capacity || index >= v->size)
		return (NULL);
	return (v->data[index]);
}
