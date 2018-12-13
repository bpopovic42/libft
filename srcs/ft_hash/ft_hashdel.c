/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 00:16:59 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/13 17:46:57 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_hashdel(t_hash *hash, void (*del)(void *))
{
	free(hash->key);
	hash->key = NULL;
	del(hash->data);
	hash->data = NULL;
	hash->data_size = 0;
	free(hash);
}
