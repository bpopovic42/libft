/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:59:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/06/01 18:25:01 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	TODO: Check if key already exists in list (ERROR case)
*/

int		ft_hashadd(t_hash **list, int key, void *data, size_t size)
{
	if (list)
	{
		ft_hashpush(list, ft_hashnew(key, data, size));
		return (1);
	}
	return (-1);
}
