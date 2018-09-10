/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:46:28 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:23:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t slen;
	size_t dlen;

	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dlen >= size)
		return (size + slen);
	if (slen < (size - dlen))
		ft_strncpy(dst + dlen, src, slen + 1);
	else
		ft_memcpy(dst + dlen, src, size - dlen);
	dst[size - 1] = '\0';
	return (dlen + slen);
}
