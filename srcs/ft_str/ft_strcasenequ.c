/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasenequ.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:57:38 by bopopovi          #+#    #+#             */
/*   Updated: 2018/08/23 17:25:42 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasenequ(char const *s1, char const *s2, size_t n)
{
	if (n == 0)
		return (1);
	while (--n && *s1 && ft_toupper(*s1) == ft_toupper(*s2))
	{
		s1++;
		s2++;
	}
	return (ft_toupper(*s1) == ft_toupper(*s2) ? 1 : 0);
}
