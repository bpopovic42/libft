/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:05:04 by bopopovi          #+#    #+#             */
/*   Updated: 2021/05/03 18:05:21 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nbr)
{
	size_t	int_length;
	t_uint	tmp;

	int_length = 1;
	tmp = nbr < 0 ? (t_uint)-nbr : (t_uint)nbr;
	while (tmp)
	{
		tmp /= 10;
		int_length++;
	}
	int_length += nbr < 0 ? 0 : -1;
	return (int_length);
}
