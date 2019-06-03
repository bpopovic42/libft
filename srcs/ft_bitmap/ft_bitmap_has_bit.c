/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap_has_bit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:22:04 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:22:32 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_bitmap_has_bit(t_bmap *bmap, size_t bit)
{
	size_t index;
	size_t offset;

	index = bit / (sizeof(int) * 8);
	offset = bit % (sizeof(int) * 8);
	return (bmap->bits[index] & (1 << offset));
}
