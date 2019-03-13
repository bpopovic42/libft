/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:11:06 by bopopovi          #+#    #+#             */
/*   Updated: 2019/03/13 21:10:08 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_lstadd_data(t_list *alst, void *data, size_t data_size)
{
	t_node *new;

	new = NULL;
	if (!(new = ft_node_new(data, data_size)))
		return (-1);
	ft_printf("adding node %p\n", new);
	ft_lstadd(alst, new);
	return (0);
}
