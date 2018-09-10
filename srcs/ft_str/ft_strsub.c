/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:15:33 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/25 20:43:44 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (len < (ft_strlen(s) - start))
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
