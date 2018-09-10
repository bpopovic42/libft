/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:18:06 by bopopovi          #+#    #+#             */
/*   Updated: 2018/07/12 17:07:16 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_bits(uint64_t val, size_t type)
{
	int size;

	size = (int)((type * 8) - 1);
	while (size >= 0)
	{
		if ((val >> size) > 0)
		{
			ft_putchar('1');
			val ^= (1 << size);
		}
		else
			ft_putchar('0');
		size--;
	}
}
