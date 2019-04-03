/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_tail_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bopopovi <bopopovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 06:07:48 by bopopovi          #+#    #+#             */
/*   Updated: 2019/04/03 06:14:11 by bopopovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstget_tail_data(t_list *list)
{
	t_node *ptr;

	if ((ptr = ft_lstget_tail(list)))
		return (ptr->data);
	return (NULL);
}
