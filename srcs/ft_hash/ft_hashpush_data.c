/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashpush_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 01:34:38 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/24 01:36:54 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashpush_data(t_htable *table, char *key, void *data, size_t size)
{
	t_hash *new_hash;

	new_hash = ft_hashnew(key, data, size);
	ft_hashpush(table, new_hash);
}
