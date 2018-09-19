/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 16:18:15 by bopopovi          #+#    #+#             */
/*   Updated: 2018/09/13 17:31:09 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long			ft_atol(const char *str)
{
	long long	res;
	int			flag;

	res = 0;
	while (ft_isspace(*str))
		str++;
	flag = *str == '-' ? -1 : 1;
	str += *str == '-' || *str == '+' ? 1 : 0;
	while (*str && (*str >= '0' && *str <= '9'))
		res = (res * 10) + (*str++ - '0');
	return ((long)(res * flag));
}
