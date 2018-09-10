/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:23:22 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:42:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_uchar *dst_ptr;
	t_uchar *src_ptr;

	dst_ptr = (t_uchar*)dst;
	src_ptr = (t_uchar*)src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
