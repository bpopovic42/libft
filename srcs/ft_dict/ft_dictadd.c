/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 17:59:17 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:16:09 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	TODO: Check if key already exists in list (ERROR case)
*/

int		ft_dictadd(t_dict **list, int key, void *data, size_t size)
{
	if (list)
	{
		ft_dictpush(list, ft_dictnew(key, data, size));
		return (1);
	}
	return (-1);
}
