/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:22:37 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:23:02 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bmap	*ft_bitmap_dup(t_bmap *bmap)
{
	t_bmap *new;

	if (!(new = ft_memalloc(sizeof(int) * bmap->size)))
		return (NULL);
	if (!(new->bits = ft_memdup(bmap->bits, sizeof(int) * bmap->size)))
		return (NULL);
	new->size = bmap->size;
	return (new);
}
