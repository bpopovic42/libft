/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:44:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/13 20:03:11 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hash		*ft_hashnew(char *key, void *data, size_t data_size)
{
	t_hash *new;

	if (!(new = (t_hash*)malloc(sizeof(*new))))
		return (NULL);
	new->next = NULL;
	new->key = ft_strdup(key);
	new->data = data;
	new->data_size = data_size;
	return (new);
}
