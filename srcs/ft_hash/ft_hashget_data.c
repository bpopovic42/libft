/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashget_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 00:12:43 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/24 00:26:03 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hashget_data(t_htable *table, char *key)
{
	t_hash *ptr;

	if ((ptr = ft_hashget(table, key)))
		return (ptr->data);
	return (NULL);
}
