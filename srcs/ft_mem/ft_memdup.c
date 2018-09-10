/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:01:46 by bopopovi          #+#    #+#             */
/*   Updated: 2018/06/01 20:01:50 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void *dup;

	dup = NULL;
	if (src)
	{
		dup = ft_memalloc(n);
		dup = ft_memcpy(dup, src, n);
	}
	return (dup);
}
