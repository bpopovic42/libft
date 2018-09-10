/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimlol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:45:47 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:31:14 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*res;

	while (ft_isspace(*s))
		s++;
	if ((len = ft_strlen(s)))
	{
		while (ft_isspace(s[len - 1]))
			len--;
	}
	if (!(res = ft_strsub(s, 0, len)))
		return (NULL);
	return (res);
}
