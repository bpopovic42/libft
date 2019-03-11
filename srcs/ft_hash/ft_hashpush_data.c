/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashpush_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 01:34:38 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/11 19:05:39 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hashpush_data(t_htable *table, char *key, void *data, size_t size)
{
	t_hash *new_hash;

	if (!(new_hash = ft_hashnew(key, data, size)))
		return (-1);
	ft_hashpush(table, new_hash);
	return (0);
}
