/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:42:11 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:47:38 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

static void		print_addr(t_uint addr)
{
	t_uint i;
	t_uint padding;

	i = 1;
	padding = 8;
	while ((i *= 16) <= addr)
		padding--;
	while (padding-- > 0)
		ft_putchar('0');
	if (i > 1)
		ft_putnbr_base((int)addr, "0123456789abcdef");
	ft_putchar(':');
}

static void		print_contents(t_uchar *buf, t_uint addr, t_uint size)
{
	long int i;
	long int j;

	i = 0;
	j = 2;
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (buf[i] < 16 && (addr + i) < size)
			ft_putchar('0');
		if (addr + i < size)
			ft_putnbr_base((int)buf[i], "0123456789abcdef");
		else
			ft_putstr("  ");
		i++;
	}
	ft_putstr(" |");
	i = -1;
	while (++i < 16 && (addr + i < size))
		!ft_isprint((char)buf[i]) ? ft_putchar('.') : ft_putchar((char)buf[i]);
	ft_putchar('|');
}

void			*ft_print_memory(void *addr, t_uint size)
{
	t_uchar	*buf;
	t_uint	i;
	t_uint	j;

	buf = (t_uchar*)addr;
	i = 0;
	j = 0;
	if (size > 0)
	{
		while (i < size)
		{
			print_addr(i);
			print_contents(buf, i, size);
			ft_putstr("\n");
			i += 16;
			buf += 16;
		}
	}
	return (addr);
}
