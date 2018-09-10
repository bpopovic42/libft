/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:59:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/16 16:41:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	t_uchar *dst_ptr;
	t_uchar *src_ptr;

	dst_ptr = (t_uchar*)dst;
	src_ptr = (t_uchar*)src;
	while (n--)
	{
		*dst_ptr++ = *src_ptr;
		if (*src_ptr == (t_uchar)c)
			return (dst_ptr);
		src_ptr++;
	}
	return (NULL);
}
