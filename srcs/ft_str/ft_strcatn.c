/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 12:37:34 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:04:13 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

char	*ft_strcatn(char *s1, size_t ac, ...)
{
	va_list	ap;
	char	*tmp;
	size_t	i;

	i = 0;
	if (ac > 0)
	{
		if (s1 == NULL)
			return (NULL);
		va_start(ap, ac);
		while (i < ac)
		{
			tmp = va_arg(ap, char*);
			ft_strcat(s1, tmp);
			i++;
		}
		va_end(ap);
	}
	return (s1);
}
