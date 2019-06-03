/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitmap_clear_bit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:21:30 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/03 18:21:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitmap_clear_bit(t_bmap *bmap, size_t bit)
{
	size_t index;
	size_t offset;

	index = bit / (sizeof(int) * 8);
	offset = bit % (sizeof(int) * 8);
	bmap->bits[index] &= ~(1 << offset);
}
