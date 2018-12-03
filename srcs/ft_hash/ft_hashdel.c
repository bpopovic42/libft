/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:16:59 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 19:54:34 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_hashdel(t_htable *table, char *key)
{
	t_hash	*elem;

	elem = ft_hashpop(table, key);
	ft_strdel(&elem->key);
	elem->data_size = 0;
	elem->next = NULL;
	ft_memdel(elem->data);
	ft_memdel((void*)elem);
}
