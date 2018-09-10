/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 17:51:41 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/24 20:22:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t len)
{
	size_t flen;

	if ((!*src) && !(*find) && len)
		return ((char*)src);
	flen = ft_strlen(find);
	while (*src && len-- >= flen)
	{
		if (ft_strnequ(src, find, flen))
			return ((char*)src);
		src++;
	}
	return (NULL);
}
