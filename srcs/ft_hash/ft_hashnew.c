/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:44:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 19:51:35 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hash		*ft_hashnew(char *key, void const *data, size_t data_size)
{
	t_hash *new;

	if (!(new = (t_hash*)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	new->key = key;
	if (data == NULL)
	{
		new->data = NULL;
		new->data_size = 0;
	}
	else
	{
		if (!(new->data = ft_memdup(data, data_size)))
			return (NULL);
		new->data_size = data_size;
	}
	return (new);
}
