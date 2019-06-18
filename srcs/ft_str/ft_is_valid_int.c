/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 00:42:54 by bopopovi          #+#    #+#             */
/*   Updated: 2019/06/18 21:42:44 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_valid_int(const char *nbr)
{
	int i;

	i = 0;
	while (nbr[i])
	{
		if (i > 0 && ft_issign(nbr[i]))
			return (0);
		else if (!ft_isdigit(nbr[i]) && !ft_issign(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}
