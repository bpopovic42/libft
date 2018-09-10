/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:34:18 by bopopovi          #+#    #+#             */
/*   Updated: 2018/07/31 03:41:30 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s)
		{
			if (!(*s ^ c))
				return ((char*)s);
			s++;
		}
		if (!(*s ^ c))
			return ((char*)s);
	}
	return (NULL);
}
