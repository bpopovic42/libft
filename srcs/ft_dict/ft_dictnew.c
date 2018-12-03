/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:44:37 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:16:17 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dict		*ft_dictnew(int key, void const *data, size_t data_size)
{
	t_dict *new;

	if (!(new = (t_dict*)malloc(sizeof(*new))))
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
