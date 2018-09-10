/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:51:15 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/17 21:23:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if base string is correct, return 1 if so
*/

static int		is_valid_base(char *base)
{
	size_t	i;

	i = 0;
	while (base[i] && !ft_issign(base[i]) && ft_char_count(base, base[i]) <= 1)
		i++;
	return (i > 1 && !base[i] ? 1 : 0);
}

/*
** Writes n expressed in *base form to stdout, returns 1 on error 0 otherwise
*/

int				ft_putnbr_base(int n, char *base)
{
	size_t tmp;
	size_t b_len;

	if (!base || !is_valid_base(base))
		return (1);
	b_len = ft_strlen(base);
	if (n < 0)
		ft_putchar('-');
	tmp = n < 0 ? (size_t)(-n) : (size_t)(n);
	if (tmp >= b_len)
		ft_putnbr_base((int)(tmp / b_len), base);
	ft_putchar(base[tmp % b_len]);
	return (0);
}
