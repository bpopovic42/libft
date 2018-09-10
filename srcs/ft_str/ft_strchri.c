/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:34:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/28 17:00:31 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchri(const char *s, int c)
{
	int i;

	i = 0;
	if (s)
	{
		while ((char)c != s[i] && s[i])
			i++;
		if ((char)c == s[i])
			return (i);
		else
			return (-1);
	}
	return (-1);
}
