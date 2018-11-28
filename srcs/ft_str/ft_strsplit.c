/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:16:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/28 16:47:43 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			**ft_strsplit(char const *s, char *split)
{
	size_t	i;
	size_t	size;
	char	**res;

	size = ft_count_words(s, split);
	if (!(res = (char**)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = NULL;
	size = 0;
	while (*s)
	{
		i = 0;
		if (ft_strchr(split, *s))
			s++;
		else
		{
			while (s[i] && !ft_strchr(split, s[i]))
				i++;
			if (!(res[size] = ft_strsub(s, 0, i)))
				return (NULL);
			size++;
		}
		s += i;
	}
	return (res);
}
