/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 11:17:07 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:41:20 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_uchar	*dst_ptr;
	t_uchar	*src_ptr;

	dst_ptr = (t_uchar*)dst;
	src_ptr = (t_uchar*)src;
	if (src_ptr < dst_ptr)
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
	}
	else
	{
		while (len--)
			*dst_ptr++ = *src_ptr++;
	}
	return (dst);
}
