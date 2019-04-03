/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_back_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:08:29 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:25:08 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstpush_back_data(t_list *list, void *d, size_t d_size)
{
	t_node *new;

	if (!(new = ft_node_new(d, d_size)))
		return (-1);
	ft_lstpush_back(list, new);
	return (0);
}
