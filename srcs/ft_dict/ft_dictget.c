/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 23:52:12 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/22 17:04:26 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	erase_data(void **data, size_t data_size)
{
	(*data) = NULL;
	data_size = 0;
}

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
			data = ptr->data;
			ft_dictdel(&ptr, &erase_data);
			return (data);
		}
	}
	return (NULL);
}
