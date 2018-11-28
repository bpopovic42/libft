/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:15:33 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/28 20:11:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (len <= (size_t)(ft_strlen(s) - (int)start))
	{
		if (!(dst = ft_strnew(len)))
			return (NULL);
		i = 0;
		while (i < len)
			dst[i++] = s[start++];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
