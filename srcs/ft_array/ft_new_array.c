/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 19:15:10 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/19 14:29:34 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_new_array(size_t x, size_t y, size_t data_size)
{
	void	**new_array;
	size_t	i;

	i = 0;
	if (!(new_array = malloc(sizeof(*new_array) * x)))
		return (NULL);
	while (i < x)
	{
		if (!(new_array[i] = malloc(data_size * y)))
		{
			free(new_array);
			return (NULL);
		}
		ft_bzero(new_array[i], data_size * y);
		i++;
	}
	return (new_array);
}
