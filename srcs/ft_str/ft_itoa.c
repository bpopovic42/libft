/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:17:08 by bopopovi          #+#    #+#             */
/*   Updated: 2018/04/28 02:33:44 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int			i;
	t_uint		tmp;
	char		*res;

	i = 1;
	tmp = n < 0 ? (t_uint)-n : (t_uint)n;
	while (tmp > 9)
	{
		tmp /= 10;
		i++;
	}
	i += n < 0 ? 0 : -1;
	if (!(res = ft_strnew((size_t)(i + 1))))
		return (NULL);
	res[i + 1] = '\0';
	tmp = n < 0 ? (t_uint)-n : (t_uint)n;
	while (i >= 0)
	{
		res[i--] = '0' + (tmp % 10);
		tmp /= 10;
	}
	res[0] = n < 0 ? '-' : res[0];
	return (res);
}
