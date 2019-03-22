/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:59:17 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/22 16:29:56 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	TODO: Check if key already exists in list (ERROR case)
*/

int		ft_dictadd(t_dict **list, int key, void *data, size_t size)
{
	t_dict *new;

	new = NULL;
	if (list)
	{
		if (!(new = ft_dictnew(key, data, size)))
			return (-1);
		ft_dictpush(list, new);
		return (1);
	}
	return (-1);
}
