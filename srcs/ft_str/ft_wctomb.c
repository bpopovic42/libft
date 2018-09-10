/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:48:00 by bopopovi          #+#    #+#             */
/*   Updated: 2018/07/30 15:57:09 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wctomb(unsigned char *s, wchar_t wc)
{
	int	shift;
	int i;

	i = 0;
	if (wc > 65536)
		shift = 18;
	else if (wc > 2048)
		shift = 12;
	else
		shift = 6;
	if (!s || !wc || (wc > 255 && MB_CUR_MAX != 4) || wc < 0x0
		|| (wc >= 0xd800 && wc <= 0xdfff) || wc > 0x10ffff)
		return (-1);
	s[0] = wc <= 128 || (MB_CUR_MAX != 4 && wc <= 256) ? wc : 64;
	if (wc < 128 || (MB_CUR_MAX != 4 && wc <= 256))
		return (1);
	s[0] += wc > 2048 ? 32 : 0;
	s[0] += wc > 65536 ? 16 : 0;
	while (shift >= 0)
	{
		s[i++] += (wc >> shift) + 128;
		wc ^= (wc >> shift) << shift;
		shift -= 6;
	}
	return (i);
}
