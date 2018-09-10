/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:34:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/07/28 02:50:30 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrn(const char *s, int c)
{
	int		occur;

	occur = 0;
	if (s)
	{
		while (*s)
		{
			if (*s == (char)c)
				occur++;
			s++;
		}
	}
	return (occur);
}
