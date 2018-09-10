/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:02:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/08/23 16:55:51 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcasestr(const char *src, const char *find)
{
	size_t flen;

	flen = ft_strlen(find);
	if (!*src && !*find)
		return ((char*)src);
	while (*src)
	{
		if (ft_strcasenequ(src, find, flen))
			return ((char*)src);
		src++;
	}
	return (NULL);
}
