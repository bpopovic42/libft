/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 19:12:25 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/25 16:30:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	t_uint	len;
	t_uint	i;
	char	*map;

	len = (t_uint)ft_strlen(s);
	i = 0;
	if (!(map = (char*)malloc(sizeof(*map) * len + 1)))
		return (NULL);
	map[len] = '\0';
	while (s[i])
	{
		map[i] = f(s[i]);
		i++;
	}
	return (map);
}
