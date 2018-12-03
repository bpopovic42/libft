/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:52:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/12/03 20:16:14 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dictget(t_dict **list, int key)
{
	t_dict	*ptr;
	void	*data;

	data = NULL;
	if (*list)
	{
		ptr = ft_dictpop(list, key);
		if (ptr)
		{
			if (!(data = ft_memdup(ptr->data, ptr->data_size)))
				return (NULL);
			ft_dictdel(&ptr);
			return (data);
		}
	}
	return (NULL);
}
