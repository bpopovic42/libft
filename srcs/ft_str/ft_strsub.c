/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:15:33 by bopopovi          #+#    #+#             */
/*   Updated: 2019/05/22 14:42:37 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start < s_len && start + len <= s_len)
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
