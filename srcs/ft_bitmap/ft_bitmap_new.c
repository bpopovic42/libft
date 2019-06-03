/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:19:57 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:20:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bmap	*ft_bitmap_new(size_t binary_size)
{
	size_t total_size;
	t_bmap *new;

	total_size = (binary_size / (sizeof(int) * 8));
	if ((total_size * (sizeof(int) * 8)) < binary_size)
		total_size++;
	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	if (!(new->bits = ft_memalloc(sizeof(int) * total_size)))
		return (NULL);
	new->size = total_size;
	return (new);
}
