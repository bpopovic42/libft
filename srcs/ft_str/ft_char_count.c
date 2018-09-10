/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpopov <bpopov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 01:40:20 by bpopov            #+#    #+#             */
/*   Updated: 2018/05/17 21:23:15 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count occurences of find in s, return count
*/

int		ft_char_count(char *s, char find)
{
	int count;

	count = 0;
	while (*s)
	{
		if (*s == find)
			count++;
		s++;
	}
	return (count);
}
