/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:00:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/27 19:34:51 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count_words(const char *s, const char *spaces)
{
	size_t word_count;

	word_count = 0;
	while (*s)
	{
		if (ft_strchr(spaces, *s))
			s++;
		else
		{
			word_count++;
			while (!ft_strchr(spaces, *s))
				s++;
		}
	}
	return (word_count);
}
