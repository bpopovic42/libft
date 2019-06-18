/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:49:43 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/18 21:41:52 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		compare_blocks(const char *p1, const char *p2, size_t block, size_t n)
{
	size_t i;

	i = block * sizeof(t_word);
	while (i < n)
	{
		if (p1[i] ^ p2[i] || p1[i] == 0 || p2[i] == 0)
			break ;
		i++;
	}
	return (int)((unsigned char)p1[i] - (unsigned char)p2[i]);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_word	*p1;
	t_word	*p2;
	size_t	block;
	size_t	len;

	p1 = (t_word*)s1;
	p2 = (t_word*)s2;
	block = 0;
	if (n != 0)
	{
		len = n / sizeof(t_word);
		if (n <= sizeof(t_word))
			len = 0;
		while (block < len)
		{
			if (p1[block] ^ p2[block])
				return (compare_blocks(s1, s2, block, n));
			block++;
		}
		return (compare_blocks(s1, s2, block, n));
	}
	return (0);
}
