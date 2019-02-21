/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 14:23:22 by bopopovi          #+#    #+#             */
/*   Updated: 2019/02/20 17:44:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copy n bytes, byte per byte, from src into dst, don't forget additional
** NULL byte if you copy strings !
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst_ptr;
	char *src_ptr;

	dst_ptr = (char*)dst;
	src_ptr = (char*)src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
