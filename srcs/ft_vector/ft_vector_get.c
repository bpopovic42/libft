/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 04:28:23 by bopopovi          #+#    #+#             */
/*   Updated: 2019/01/03 21:19:40 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vector_get(t_vect *v, size_t index)
{
	if (!v || index > v->size)
		return (NULL);
	return (v->data[index]);
}
