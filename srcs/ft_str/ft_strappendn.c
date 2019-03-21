/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappendn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:50:36 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/21 20:13:28 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strappendn(char *dst, size_t ac, ...)
{
	size_t	i;
	va_list	ap;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if (ac > 0)
	{
		va_start(ap, ac);
		while (i < ac)
		{
			tmp = va_arg(ap, char*);
			if (tmp)
			{
				if (!(dst = ft_strappend(dst, tmp)))
				{
					ft_strdel(&dst);
					return (NULL);
				}
			}
			i++;
		}
		va_end(ap);
	}
	return (dst);
}
