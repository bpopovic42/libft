/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:49:43 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:23:22 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const t_uchar *p1;
	const t_uchar *p2;

	p1 = (const t_uchar*)s1;
	p2 = (const t_uchar*)s2;
	if (n != 0)
	{
		while (n--)
		{
			if (*p1 != *p2++)
				return (*p1 - *--p2);
			if (*p1++ == 0)
				return (0);
		}
	}
	return (0);
}
