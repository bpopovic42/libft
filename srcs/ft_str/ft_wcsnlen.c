/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:31:39 by bopopovi          #+#    #+#             */
/*   Updated: 2018/07/30 15:54:47 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wcsnlen(wchar_t *wcs, size_t n)
{
	size_t	i;
	size_t	bytes;
	size_t	total_b;

	i = 0;
	bytes = 0;
	total_b = 0;
	if (wcs)
	{
		while (wcs[i] != L'\0' && total_b < n)
		{
			bytes = 0;
			if ((wcs[i] > 255 && MB_CUR_MAX != 4) || wcs[i] < 0x0
				|| (wcs[i] >= 0xd800 && wcs[i] <= 0xdfff) || wcs[i] > 0x10ffff)
				return (-1);
			bytes += wcs[i] > 65536 && MB_CUR_MAX == 4 ? 1 : 0;
			bytes += wcs[i] > 2048 && MB_CUR_MAX == 4 ? 1 : 0;
			bytes += wcs[i] > 128 && MB_CUR_MAX == 4 ? 1 : 0;
			bytes++;
			total_b += bytes;
			i++;
		}
		total_b -= total_b > n ? bytes : 0;
	}
	return (total_b);
}
