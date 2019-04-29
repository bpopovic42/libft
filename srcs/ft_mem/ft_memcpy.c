/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:23:22 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/29 16:45:31 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy n bytes, byte per byte, from src into dst, don't forget additional
** NULL byte if you copy strings !
** t_word must be a power of 2 for AND modulo to work
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		len;
	size_t		wsize;
	char		*dst_ptr;
	const char	*src_ptr;

	dst_ptr = (char*)dst;
	src_ptr = (char*)src;
	wsize = sizeof(t_word);
	len = n / wsize;
	while (len--)
	{
		*(t_word*)dst_ptr = *(t_word*)src_ptr;
		dst_ptr += wsize;
		src_ptr += wsize;
	}
	len = n & (wsize - 1);
	while (len--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
