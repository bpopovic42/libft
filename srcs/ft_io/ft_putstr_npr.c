/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_npr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:08:03 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/11 18:14:05 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_npr(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str == 127)
		{
			ft_putchar('\\');
			ft_putnbr_base((int)*str, "01234567");
		}
		else
			ft_putchar(*str);
		str++;
	}
}
