/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:30:38 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:30:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_uint	i;
	t_uint	len;
	char	*map;

	i = 0;
	len = (t_uint)ft_strlen(s);
	if (!(map = (char*)malloc(sizeof(*map) * len + 1)))
		return (NULL);
	map[len] = '\0';
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	return (map);
}
