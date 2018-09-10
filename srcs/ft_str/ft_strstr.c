/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:02:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/08/29 03:47:27 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *find)
{
	size_t flen;

	flen = ft_strlen(find);
	if (!*src && !*find)
		return ((char*)src);
	while (*src)
	{
		if (ft_strnequ(src, find, flen))
			return ((char*)src);
		src++;
	}
	return (NULL);
}
