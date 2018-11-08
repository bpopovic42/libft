/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:16:50 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/21 23:48:24 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c)
{
	size_t res;

	res = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*s != c)
		{
			res++;
			while (*s && *s != c)
				s++;
		}
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	size;
	char	**res;

	size = count_words(s, c);
	if (!(res = (char**)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = NULL;
	size = 0;
	while (*s)
	{
		i = 0;
		if (*s == c)
			s++;
		else if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			if (!(res[size] = ft_strsub(s, 0, i)))
				return (NULL);
			size++;
		}
		s += i;
	}
	return (res);
}
