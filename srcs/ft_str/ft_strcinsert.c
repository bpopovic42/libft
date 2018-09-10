/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 23:54:12 by bopopovi          #+#    #+#             */
/*   Updated: 2018/06/26 00:26:08 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcinsert(char *str, char ins, size_t pos)
{
	size_t		i;

	if (str == NULL)
		return (-1);
	i = ft_strlen(str) + 1;
	while (i > pos)
	{
		if (i - 1 >= pos)
			str[i] = str[i - 1];
		i--;
	}
	str[i] = ins;
	return (0);
}
