/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 19:26:49 by bopopovi          #+#    #+#             */
/*   Updated: 2018/05/24 21:38:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char *res;

	res = NULL;
	if (s1)
	{
		if (!(res = (char*)malloc(sizeof(*res) * ft_strlen(s1) + 1)))
			return (NULL);
		res = ft_strcpy(res, s1);
	}
	return (res);
}
