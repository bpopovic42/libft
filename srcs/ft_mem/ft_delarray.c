/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:08:53 by bopopovi          #+#    #+#             */
/*   Updated: 2018/11/29 19:43:22 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delarray(void *array)
{
	size_t i;

	i = 0;
	while (((void**)array)[i])
	{
		free(((void**)array)[i]);
		i++;
	}
	free(array);
}
