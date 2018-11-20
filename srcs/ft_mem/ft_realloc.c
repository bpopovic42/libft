/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 03:13:38 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/20 05:18:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void *new_ptr;

	if (!(new_ptr = ft_memalloc(new_size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		ft_memdel(&ptr);
	}
	ptr = new_ptr;
	return (ptr);
}
