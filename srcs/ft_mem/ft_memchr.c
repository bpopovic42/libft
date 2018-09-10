/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:42:57 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:40:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar *ptr;

	ptr = (t_uchar*)s;
	while (n--)
	{
		if (*ptr == (t_uchar)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
